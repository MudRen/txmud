// Room: /d/hangzhou/zfwife2.c

inherit ROOM;

void create()
{
	set("short", "�������Է�");
	set("long", @LONG
���Ǻ���֪�������˵ķ��䣬��������֪�����������ڱ��
��֪��ʱ��Ȣ��ƶ��Ů�ӣ�Ϊ֪������һŮ�������˵ķ������
�����Ǽ��ӡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"zfpath9",
]));

	setup();
	replace_program(ROOM);
}
