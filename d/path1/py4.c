// Room: /d/path1/py4.c

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
  "west" : __DIR__"py5",
  "southeast" : __DIR__"py3",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
