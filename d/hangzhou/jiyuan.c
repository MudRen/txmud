// Room: /d/hangzhou/jiyuan.c

inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
����ÿ�����Ӷ����ţ�ÿ������ж����м�Ժ��������Ǻ�
�ݳ�������һ�䣬�պ�һ�������˱��������ﵱȻҲ�ǻ�����
�ݣ�Ӧ�о��С�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"minan04",
  "east" : __DIR__"jiyuan01",
]));

	setup();
	replace_program(ROOM);
}
