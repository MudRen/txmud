// Room: /d/path5/kch50.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����һ������С·����ÿ��һ������������Щ������Ū��
��ò��ķ����㵧�˵��������ϵĻҳ������ε�̾�˿���������
ǰ�аɡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"kch51",
  "northwest" : __DIR__"kch49",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
