// Room: /d/path2/ch_t9.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
������������ϣ�̧ͷ��ȥ���������죬��ɫ���ˡ���Ȼ��
�д���һ����ֵĽ�������֪��ʲô������������һ������æ��
���˽Ų���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ch_t8",
  "northwest" : __DIR__"ch_t13",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
