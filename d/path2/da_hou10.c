// Room: /d/path2/da_hou10.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ������С·��һ����ͣ��·�ԣ�������Ͱ������·
�ߣ��������Χ�Źۿ������߽�ǰȥ��һ����ζӭ��������ԭ��
���ʹ׵ĳ����ˣ��ֲ�����ô�����ζ���������ǰ��ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"da_hou9",
  "south" : "/d/houmaji",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
