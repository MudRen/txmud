// Room: /d/path1/py3.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��������᫵�ɽ·�������С�̧ͷ��ȥ��������һ����ɽ��
ɽ����ɫ�Ĵ����к�����ʲô�����ڻζ���������һ�������ɵ�
�ӿ�Ų���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"py2",
  "northwest" : __DIR__"py4",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
