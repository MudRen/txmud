// Room: /d/path3/fengd8.c

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
  "south" : __DIR__"fengd5",
  "west" : __DIR__"fengd9",
  "east" : __DIR__"fengd7",
]));

	set("outdoors", "mafeng");
	setup();
}