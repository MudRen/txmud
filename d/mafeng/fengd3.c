// Room: /d/path3/fengd3.c

inherit ROOM;

void create()
{
	set("short", "��ɽ����");
	set("long",  @LONG
������һСƬŨ�ܵ����֣�����Ĺ���������գ���������
����Ŀ�֦��Ҷ��ɽ�紵���Ĵ�ɳɳ���룬˵��������ɭ�ֲ���
LONG
);
	set("exits", ([
  "north" : __DIR__"fengd6",
  "east" : __DIR__"fengd2",
]));

	set("outdoors", "mafeng");
	setup();
}