// Room: /d/hangzhou/zfyuanzi.c

inherit ROOM;

void create()
{
	set("short", "�쾮");
	set("long", @LONG
�ƹ�һ��Ӱ��ǽ�������ǰ��һ�����쾮��һ����ʯ���·
һֱͨ�����ã�·�ߵĴ�������һ�������ܣ���������Ĺ���һ
��ˮ�����
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zfpath3",
  "south" : __DIR__"zhifu",
  "east" : __DIR__"zfpath1",
  "north" : __DIR__"zfdatang",
]));

	setup();
	replace_program(ROOM);
}
