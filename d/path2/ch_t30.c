// Room: /d/path2/ch_t30.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ������С·��·������ϡ��س���һЩ�Ӳݣ�������
����������˾������Ե�ʮ�ֻ�����������ȥ������ˮ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ch_t29",
  "west" : "/d/tianshui/xiaolu4",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
