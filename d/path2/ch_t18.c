// Room: /d/path2/ch_t18.c

inherit ROOM;

void create()
{
	set("short", "��ԭ��·");
	set("long", @LONG
�����ڻ�����ԭ�ϣ�̧�ۿ�ȥ��һ���޼ʵĻ�����ԭ�����
������������Ǹ���������㿴��Զ�������ɽ���������ٸ���
���泩��������ǻƺӺ��ס�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ch_t17",
  "west" : __DIR__"ch_t19",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
