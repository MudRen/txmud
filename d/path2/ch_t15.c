// Room: /d/path2/ch_t15.c

inherit ROOM;

void create()
{
	set("short", "������ԭ");
	set("long", @LONG
�����ڻ�����ԭ�ϣ�̧�ۿ�ȥ��һ���޼ʵĻ�����ԭ�����
������������Ǹ���������㿴��Զ�������ɽ���������ٸ���
���泩��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"ch_t14",
  "northwest" : __DIR__"ch_t16",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
