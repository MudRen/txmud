// Room: /d/path2/ch_t20.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
�����ڻ�����ԭ�ϣ�̧�ۿ�ȥ��һ���޼ʵĻ�����ԭ�����
������������Ǹ���������㿴��Զ�������ɽ���������ٸ���
���泩��������ǻƺӺ��ף��������͵��˰����ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ch_t19",
  "west" : __DIR__"ch_t21",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
