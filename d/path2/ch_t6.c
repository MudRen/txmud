// Room: /d/path2/ch_t6.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�������������·������һ���������γɵķ���ǽ��
����������Ҷɳɳ���졣����Զ����ȥ��һƬƬ������������
�ߣ���������һ�������ꡣ
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ch_t5",
  "west" : __DIR__"ch_t7",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
