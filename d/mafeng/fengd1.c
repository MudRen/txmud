// Room: /d/path3/fengd1.c

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
  "south" : __DIR__"up6",
  "north" : __DIR__"fengd4",
  "west" : __DIR__"fengd2",
]));

	set("outdoors", "mafeng");
	setup();
}