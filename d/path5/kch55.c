// Room: /d/path5/kch55.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
����һ��������������Ϲ������������Ÿ��죬���ٴ�����
��û�м�������ЩС��������Ҳ�в������Ķ����������������
״�����������Ժ��л�����˵�ɡ����治Զ���ǳɶ������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kch56",
  "north" : __DIR__"kch54",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
