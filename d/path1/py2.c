// Room: /d/path1/py2.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��������᫵�ɽ·�������С�̧ͷ��ȥ��������ǻ���ɽ��
ɽ����ɫ�Ĵ����к�����ʲô�����ڻζ���������һ�������ɵ�
�ӿ�Ų���������ɽ��һ��С·��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"py3",
  "east" : __DIR__"py1",
  "southdown" : __DIR__"lmj17",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
