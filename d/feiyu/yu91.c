// Room: /u/w/wangs/a/yu91.c

inherit ROOM;

void create()
{
    set("short", "������");
	set("long", @LONG
����һ�����ĵ�С�ᣬ����һ����Ⱦ��������������������
��ɨ��ÿ�������Ϯ�����ڶ�����ɪ֮������������Ի������������
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yu90",
]));

	setup();
	replace_program(ROOM);
}

