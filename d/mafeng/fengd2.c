// Room: /d/path3/fengd2.c

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
  "west" : __DIR__"fengd3",
  "east" : __DIR__"fengd1",
  "north" : __DIR__"fengd5",
]));

	set("outdoors", "mafeng");
	setup();
}