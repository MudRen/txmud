// Room: /d/path3/fengd5.c

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
  "south" : __DIR__"fengd2",
  "north" : __DIR__"fengd8",
  "west" : __DIR__"fengd6",
  "east" : __DIR__"fengd4",
]));

	set("outdoors", "mafeng");
	setup();
}

void init()
{
	object me;

	if(!random(3)
	|| (find_call_out("do_begin") != -1)
	|| !objectp(me = this_player())
	|| !userp(me) )
		return;
	call_out("do_begin",2);
}

protected void do_begin()
{
	object cob;

	if(!objectp(cob = find_object(__DIR__"control")) && !objectp(cob = load_object(__DIR__"control")))
		return;

	cob->query_leader();
}