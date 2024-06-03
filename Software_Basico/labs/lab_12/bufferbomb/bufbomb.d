
bufbomb:     file format elf64-x86-64


Disassembly of section .init:

0000000000401000 <_init>:
  401000:	48 83 ec 08          	sub    $0x8,%rsp
  401004:	48 8b 05 d5 2f 00 00 	mov    0x2fd5(%rip),%rax        # 403fe0 <__gmon_start__@Base>
  40100b:	48 85 c0             	test   %rax,%rax
  40100e:	74 02                	je     401012 <_init+0x12>
  401010:	ff d0                	call   *%rax
  401012:	48 83 c4 08          	add    $0x8,%rsp
  401016:	c3                   	ret

Disassembly of section .plt:

0000000000401020 <puts@plt-0x10>:
  401020:	ff 35 ca 2f 00 00    	push   0x2fca(%rip)        # 403ff0 <_GLOBAL_OFFSET_TABLE_+0x8>
  401026:	ff 25 cc 2f 00 00    	jmp    *0x2fcc(%rip)        # 403ff8 <_GLOBAL_OFFSET_TABLE_+0x10>
  40102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401030 <puts@plt>:
  401030:	ff 25 ca 2f 00 00    	jmp    *0x2fca(%rip)        # 404000 <puts@GLIBC_2.2.5>
  401036:	68 00 00 00 00       	push   $0x0
  40103b:	e9 e0 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401040 <printf@plt>:
  401040:	ff 25 c2 2f 00 00    	jmp    *0x2fc2(%rip)        # 404008 <printf@GLIBC_2.2.5>
  401046:	68 01 00 00 00       	push   $0x1
  40104b:	e9 d0 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401050 <strcmp@plt>:
  401050:	ff 25 ba 2f 00 00    	jmp    *0x2fba(%rip)        # 404010 <strcmp@GLIBC_2.2.5>
  401056:	68 02 00 00 00       	push   $0x2
  40105b:	e9 c0 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401060 <signal@plt>:
  401060:	ff 25 b2 2f 00 00    	jmp    *0x2fb2(%rip)        # 404018 <signal@GLIBC_2.2.5>
  401066:	68 03 00 00 00       	push   $0x3
  40106b:	e9 b0 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401070 <exit@plt>:
  401070:	ff 25 aa 2f 00 00    	jmp    *0x2faa(%rip)        # 404020 <exit@GLIBC_2.2.5>
  401076:	68 04 00 00 00       	push   $0x4
  40107b:	e9 a0 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401080 <getc@plt>:
  401080:	ff 25 a2 2f 00 00    	jmp    *0x2fa2(%rip)        # 404028 <getc@GLIBC_2.2.5>
  401086:	68 05 00 00 00       	push   $0x5
  40108b:	e9 90 ff ff ff       	jmp    401020 <_init+0x20>

Disassembly of section .text:

0000000000401090 <_start>:
  401090:	31 ed                	xor    %ebp,%ebp
  401092:	49 89 d1             	mov    %rdx,%r9
  401095:	5e                   	pop    %rsi
  401096:	48 89 e2             	mov    %rsp,%rdx
  401099:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  40109d:	50                   	push   %rax
  40109e:	54                   	push   %rsp
  40109f:	45 31 c0             	xor    %r8d,%r8d
  4010a2:	31 c9                	xor    %ecx,%ecx
  4010a4:	48 c7 c7 5d 13 40 00 	mov    $0x40135d,%rdi
  4010ab:	ff 15 27 2f 00 00    	call   *0x2f27(%rip)        # 403fd8 <__libc_start_main@GLIBC_2.34>
  4010b1:	f4                   	hlt
  4010b2:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
  4010b9:	00 00 00 
  4010bc:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004010c0 <_dl_relocate_static_pie>:
  4010c0:	c3                   	ret
  4010c1:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
  4010c8:	00 00 00 
  4010cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000004010d0 <deregister_tm_clones>:
  4010d0:	b8 40 40 40 00       	mov    $0x404040,%eax
  4010d5:	48 3d 40 40 40 00    	cmp    $0x404040,%rax
  4010db:	74 13                	je     4010f0 <deregister_tm_clones+0x20>
  4010dd:	b8 00 00 00 00       	mov    $0x0,%eax
  4010e2:	48 85 c0             	test   %rax,%rax
  4010e5:	74 09                	je     4010f0 <deregister_tm_clones+0x20>
  4010e7:	bf 40 40 40 00       	mov    $0x404040,%edi
  4010ec:	ff e0                	jmp    *%rax
  4010ee:	66 90                	xchg   %ax,%ax
  4010f0:	c3                   	ret
  4010f1:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
  4010f8:	00 00 00 00 
  4010fc:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401100 <register_tm_clones>:
  401100:	be 40 40 40 00       	mov    $0x404040,%esi
  401105:	48 81 ee 40 40 40 00 	sub    $0x404040,%rsi
  40110c:	48 89 f0             	mov    %rsi,%rax
  40110f:	48 c1 ee 3f          	shr    $0x3f,%rsi
  401113:	48 c1 f8 03          	sar    $0x3,%rax
  401117:	48 01 c6             	add    %rax,%rsi
  40111a:	48 d1 fe             	sar    %rsi
  40111d:	74 11                	je     401130 <register_tm_clones+0x30>
  40111f:	b8 00 00 00 00       	mov    $0x0,%eax
  401124:	48 85 c0             	test   %rax,%rax
  401127:	74 07                	je     401130 <register_tm_clones+0x30>
  401129:	bf 40 40 40 00       	mov    $0x404040,%edi
  40112e:	ff e0                	jmp    *%rax
  401130:	c3                   	ret
  401131:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
  401138:	00 00 00 00 
  40113c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401140 <__do_global_dtors_aux>:
  401140:	f3 0f 1e fa          	endbr64
  401144:	80 3d fd 2e 00 00 00 	cmpb   $0x0,0x2efd(%rip)        # 404048 <completed.0>
  40114b:	75 13                	jne    401160 <__do_global_dtors_aux+0x20>
  40114d:	55                   	push   %rbp
  40114e:	48 89 e5             	mov    %rsp,%rbp
  401151:	e8 7a ff ff ff       	call   4010d0 <deregister_tm_clones>
  401156:	c6 05 eb 2e 00 00 01 	movb   $0x1,0x2eeb(%rip)        # 404048 <completed.0>
  40115d:	5d                   	pop    %rbp
  40115e:	c3                   	ret
  40115f:	90                   	nop
  401160:	c3                   	ret
  401161:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
  401168:	00 00 00 00 
  40116c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401170 <frame_dummy>:
  401170:	f3 0f 1e fa          	endbr64
  401174:	eb 8a                	jmp    401100 <register_tm_clones>

0000000000401176 <valid>:
  401176:	55                   	push   %rbp
  401177:	48 89 e5             	mov    %rsp,%rbp
  40117a:	48 83 ec 10          	sub    $0x10,%rsp
  40117e:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  401182:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401186:	48 8d 15 7b 0e 00 00 	lea    0xe7b(%rip),%rdx        # 402008 <_IO_stdin_used+0x8>
  40118d:	48 89 d6             	mov    %rdx,%rsi
  401190:	48 89 c7             	mov    %rax,%rdi
  401193:	e8 b8 fe ff ff       	call   401050 <strcmp@plt>
  401198:	85 c0                	test   %eax,%eax
  40119a:	0f 94 c0             	sete   %al
  40119d:	0f b6 c0             	movzbl %al,%eax
  4011a0:	c9                   	leave
  4011a1:	c3                   	ret

00000000004011a2 <danger>:
  4011a2:	55                   	push   %rbp
  4011a3:	48 89 e5             	mov    %rsp,%rbp
  4011a6:	48 8d 05 65 0e 00 00 	lea    0xe65(%rip),%rax        # 402012 <_IO_stdin_used+0x12>
  4011ad:	48 89 c7             	mov    %rax,%rdi
  4011b0:	e8 7b fe ff ff       	call   401030 <puts@plt>
  4011b5:	48 8d 05 74 0e 00 00 	lea    0xe74(%rip),%rax        # 402030 <_IO_stdin_used+0x30>
  4011bc:	48 89 c7             	mov    %rax,%rdi
  4011bf:	e8 6c fe ff ff       	call   401030 <puts@plt>
  4011c4:	90                   	nop
  4011c5:	5d                   	pop    %rbp
  4011c6:	c3                   	ret

00000000004011c7 <protect>:
  4011c7:	55                   	push   %rbp
  4011c8:	48 89 e5             	mov    %rsp,%rbp
  4011cb:	48 83 ec 10          	sub    $0x10,%rsp
  4011cf:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  4011d3:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  4011d7:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  4011db:	48 89 c7             	mov    %rax,%rdi
  4011de:	e8 93 ff ff ff       	call   401176 <valid>
  4011e3:	85 c0                	test   %eax,%eax
  4011e5:	74 11                	je     4011f8 <protect+0x31>
  4011e7:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  4011eb:	48 89 c7             	mov    %rax,%rdi
  4011ee:	b8 00 00 00 00       	mov    $0x0,%eax
  4011f3:	e8 aa ff ff ff       	call   4011a2 <danger>
  4011f8:	90                   	nop
  4011f9:	c9                   	leave
  4011fa:	c3                   	ret

00000000004011fb <smoke>:
  4011fb:	55                   	push   %rbp
  4011fc:	48 89 e5             	mov    %rsp,%rbp
  4011ff:	48 8d 05 53 0e 00 00 	lea    0xe53(%rip),%rax        # 402059 <_IO_stdin_used+0x59>
  401206:	48 89 c7             	mov    %rax,%rdi
  401209:	e8 22 fe ff ff       	call   401030 <puts@plt>
  40120e:	bf 00 00 00 00       	mov    $0x0,%edi
  401213:	e8 58 fe ff ff       	call   401070 <exit@plt>

0000000000401218 <fizz>:
  401218:	55                   	push   %rbp
  401219:	48 89 e5             	mov    %rsp,%rbp
  40121c:	48 83 ec 10          	sub    $0x10,%rsp
  401220:	89 7d fc             	mov    %edi,-0x4(%rbp)
  401223:	81 7d fc 04 03 02 01 	cmpl   $0x1020304,-0x4(%rbp)
  40122a:	75 1b                	jne    401247 <fizz+0x2f>
  40122c:	8b 45 fc             	mov    -0x4(%rbp),%eax
  40122f:	89 c6                	mov    %eax,%esi
  401231:	48 8d 05 3c 0e 00 00 	lea    0xe3c(%rip),%rax        # 402074 <_IO_stdin_used+0x74>
  401238:	48 89 c7             	mov    %rax,%rdi
  40123b:	b8 00 00 00 00       	mov    $0x0,%eax
  401240:	e8 fb fd ff ff       	call   401040 <printf@plt>
  401245:	eb 19                	jmp    401260 <fizz+0x48>
  401247:	8b 45 fc             	mov    -0x4(%rbp),%eax
  40124a:	89 c6                	mov    %eax,%esi
  40124c:	48 8d 05 45 0e 00 00 	lea    0xe45(%rip),%rax        # 402098 <_IO_stdin_used+0x98>
  401253:	48 89 c7             	mov    %rax,%rdi
  401256:	b8 00 00 00 00       	mov    $0x0,%eax
  40125b:	e8 e0 fd ff ff       	call   401040 <printf@plt>
  401260:	bf 00 00 00 00       	mov    $0x0,%edi
  401265:	e8 06 fe ff ff       	call   401070 <exit@plt>

000000000040126a <Gets>:
  40126a:	55                   	push   %rbp
  40126b:	48 89 e5             	mov    %rsp,%rbp
  40126e:	48 83 ec 20          	sub    $0x20,%rsp
  401272:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  401276:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  40127a:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  40127e:	eb 11                	jmp    401291 <Gets+0x27>
  401280:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401284:	48 8d 50 01          	lea    0x1(%rax),%rdx
  401288:	48 89 55 f8          	mov    %rdx,-0x8(%rbp)
  40128c:	8b 55 f4             	mov    -0xc(%rbp),%edx
  40128f:	88 10                	mov    %dl,(%rax)
  401291:	48 8b 05 b8 2d 00 00 	mov    0x2db8(%rip),%rax        # 404050 <infile>
  401298:	48 89 c7             	mov    %rax,%rdi
  40129b:	e8 e0 fd ff ff       	call   401080 <getc@plt>
  4012a0:	89 45 f4             	mov    %eax,-0xc(%rbp)
  4012a3:	83 7d f4 ff          	cmpl   $0xffffffff,-0xc(%rbp)
  4012a7:	74 06                	je     4012af <Gets+0x45>
  4012a9:	83 7d f4 0a          	cmpl   $0xa,-0xc(%rbp)
  4012ad:	75 d1                	jne    401280 <Gets+0x16>
  4012af:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  4012b3:	48 8d 50 01          	lea    0x1(%rax),%rdx
  4012b7:	48 89 55 f8          	mov    %rdx,-0x8(%rbp)
  4012bb:	c6 00 00             	movb   $0x0,(%rax)
  4012be:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4012c2:	c9                   	leave
  4012c3:	c3                   	ret

00000000004012c4 <bushandler>:
  4012c4:	55                   	push   %rbp
  4012c5:	48 89 e5             	mov    %rsp,%rbp
  4012c8:	48 83 ec 10          	sub    $0x10,%rsp
  4012cc:	89 7d fc             	mov    %edi,-0x4(%rbp)
  4012cf:	48 8d 05 e2 0d 00 00 	lea    0xde2(%rip),%rax        # 4020b8 <_IO_stdin_used+0xb8>
  4012d6:	48 89 c7             	mov    %rax,%rdi
  4012d9:	e8 52 fd ff ff       	call   401030 <puts@plt>
  4012de:	48 8d 05 f3 0d 00 00 	lea    0xdf3(%rip),%rax        # 4020d8 <_IO_stdin_used+0xd8>
  4012e5:	48 89 c7             	mov    %rax,%rdi
  4012e8:	e8 43 fd ff ff       	call   401030 <puts@plt>
  4012ed:	bf 00 00 00 00       	mov    $0x0,%edi
  4012f2:	e8 79 fd ff ff       	call   401070 <exit@plt>

00000000004012f7 <seghandler>:
  4012f7:	55                   	push   %rbp
  4012f8:	48 89 e5             	mov    %rsp,%rbp
  4012fb:	48 83 ec 10          	sub    $0x10,%rsp
  4012ff:	89 7d fc             	mov    %edi,-0x4(%rbp)
  401302:	48 8d 05 e7 0d 00 00 	lea    0xde7(%rip),%rax        # 4020f0 <_IO_stdin_used+0xf0>
  401309:	48 89 c7             	mov    %rax,%rdi
  40130c:	e8 1f fd ff ff       	call   401030 <puts@plt>
  401311:	48 8d 05 c0 0d 00 00 	lea    0xdc0(%rip),%rax        # 4020d8 <_IO_stdin_used+0xd8>
  401318:	48 89 c7             	mov    %rax,%rdi
  40131b:	e8 10 fd ff ff       	call   401030 <puts@plt>
  401320:	bf 00 00 00 00       	mov    $0x0,%edi
  401325:	e8 46 fd ff ff       	call   401070 <exit@plt>

000000000040132a <illegalhandler>:
  40132a:	55                   	push   %rbp
  40132b:	48 89 e5             	mov    %rsp,%rbp
  40132e:	48 83 ec 10          	sub    $0x10,%rsp
  401332:	89 7d fc             	mov    %edi,-0x4(%rbp)
  401335:	48 8d 05 dc 0d 00 00 	lea    0xddc(%rip),%rax        # 402118 <_IO_stdin_used+0x118>
  40133c:	48 89 c7             	mov    %rax,%rdi
  40133f:	e8 ec fc ff ff       	call   401030 <puts@plt>
  401344:	48 8d 05 8d 0d 00 00 	lea    0xd8d(%rip),%rax        # 4020d8 <_IO_stdin_used+0xd8>
  40134b:	48 89 c7             	mov    %rax,%rdi
  40134e:	e8 dd fc ff ff       	call   401030 <puts@plt>
  401353:	bf 00 00 00 00       	mov    $0x0,%edi
  401358:	e8 13 fd ff ff       	call   401070 <exit@plt>

000000000040135d <main>:
  40135d:	55                   	push   %rbp
  40135e:	48 89 e5             	mov    %rsp,%rbp
  401361:	48 83 ec 10          	sub    $0x10,%rsp
  401365:	89 7d fc             	mov    %edi,-0x4(%rbp)
  401368:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  40136c:	48 8d 05 84 ff ff ff 	lea    -0x7c(%rip),%rax        # 4012f7 <seghandler>
  401373:	48 89 c6             	mov    %rax,%rsi
  401376:	bf 0b 00 00 00       	mov    $0xb,%edi
  40137b:	e8 e0 fc ff ff       	call   401060 <signal@plt>
  401380:	48 8d 05 3d ff ff ff 	lea    -0xc3(%rip),%rax        # 4012c4 <bushandler>
  401387:	48 89 c6             	mov    %rax,%rsi
  40138a:	bf 07 00 00 00       	mov    $0x7,%edi
  40138f:	e8 cc fc ff ff       	call   401060 <signal@plt>
  401394:	48 8d 05 8f ff ff ff 	lea    -0x71(%rip),%rax        # 40132a <illegalhandler>
  40139b:	48 89 c6             	mov    %rax,%rsi
  40139e:	bf 04 00 00 00       	mov    $0x4,%edi
  4013a3:	e8 b8 fc ff ff       	call   401060 <signal@plt>
  4013a8:	48 8b 05 91 2c 00 00 	mov    0x2c91(%rip),%rax        # 404040 <stdin@GLIBC_2.2.5>
  4013af:	48 89 05 9a 2c 00 00 	mov    %rax,0x2c9a(%rip)        # 404050 <infile>
  4013b6:	b8 00 00 00 00       	mov    $0x0,%eax
  4013bb:	e8 16 00 00 00       	call   4013d6 <getbuf>
  4013c0:	48 8d 05 81 0d 00 00 	lea    0xd81(%rip),%rax        # 402148 <_IO_stdin_used+0x148>
  4013c7:	48 89 c7             	mov    %rax,%rdi
  4013ca:	e8 61 fc ff ff       	call   401030 <puts@plt>
  4013cf:	b8 00 00 00 00       	mov    $0x0,%eax
  4013d4:	c9                   	leave
  4013d5:	c3                   	ret

00000000004013d6 <getbuf>:
  4013d6:	55                   	push   %rbp
  4013d7:	48 89 e5             	mov    %rsp,%rbp
  4013da:	48 83 ec 20          	sub    $0x20,%rsp
  4013de:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  4013e2:	48 89 c6             	mov    %rax,%rsi
  4013e5:	48 8d 05 80 0d 00 00 	lea    0xd80(%rip),%rax        # 40216c <_IO_stdin_used+0x16c>
  4013ec:	48 89 c7             	mov    %rax,%rdi
  4013ef:	b8 00 00 00 00       	mov    $0x0,%eax
  4013f4:	e8 47 fc ff ff       	call   401040 <printf@plt>
  4013f9:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  4013fd:	48 89 c7             	mov    %rax,%rdi
  401400:	e8 65 fe ff ff       	call   40126a <Gets>
  401405:	b8 01 00 00 00       	mov    $0x1,%eax
  40140a:	c9                   	leave
  40140b:	c3                   	ret

Disassembly of section .fini:

000000000040140c <_fini>:
  40140c:	48 83 ec 08          	sub    $0x8,%rsp
  401410:	48 83 c4 08          	add    $0x8,%rsp
  401414:	c3                   	ret
