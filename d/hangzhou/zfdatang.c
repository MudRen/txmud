// Room: /d/hangzhou/zfdatang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����֪�����ŵĴ��ã�������������Ŀ�ĵط�����һ������
���ң�����д�š������������ĸ����֣��ſڰ���һ�Ŵ�ģ���
������һ����ľ�������������һ�龪��ľ��һϻ���ơ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zfyuanzi",
  "north" : __DIR__"zfpath6",
]));

	setup();
	replace_program(ROOM);
}
