// Room: /d/hangzhou/zfpath6.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����ȣ�֪������ÿ�����ö�Ҫ�����������ȣ�����
����������ľ��̵�Χ����Χ��������һ��С��԰����԰��Ȼ��
�󣬵�ȴ�ǻ���ïʢ����ɫ��԰��

LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zfdatang",
  "west" : __DIR__"zfpath4",
]));

	setup();
	replace_program(ROOM);
}
