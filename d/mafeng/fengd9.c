// Room: /d/path3/fengd9.c

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
  "south" : __DIR__"fengd6",
  "east" : __DIR__"fengd8",
	"northwest" : __DIR__"up7",
]));

	set("outdoors", "mafeng");
	setup();
}