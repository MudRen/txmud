// Room: /d/path2/ch_t14.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
������������ϣ�̧ͷ��ȥ���������죬��ɫ���ˡ���Ȼ��
�д���һ����ֵĽ�������֪��ʲô������������һ������æ��
���˽Ų��������������򣬾ͳ������֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"ch_t13",
  "northwest" : __DIR__"ch_t15",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
