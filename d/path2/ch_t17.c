// Room: /d/path2/ch_t17.c

inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", @LONG
�����ڻ�����ԭ�ϣ�̧�ۿ�ȥ��һ���޼ʵĻ�����ԭ�����
������������Ǹ���������㿴��Զ�������ɽ���������ٸ���
���泩��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ch_t16",
  "west" : __DIR__"ch_t18",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
