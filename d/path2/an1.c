// Room: /d/path2/an1.c

inherit ROOM;

void create()
{
	set("short", "�ƺӰ���");
	set("long", @LONG
�����ǻƺ����ΰ��ߣ���ӿ�ĺ�ˮ��ʱ���Ĵ��Ű��ߣ�ŭ��
����ǰ��ȥ���˻��ɽ���ˮ���������㱻����ΰ�ľ��󾪴��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ch_k29",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
