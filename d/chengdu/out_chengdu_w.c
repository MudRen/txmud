// Room: /d/chengdu/out_chengdu_w.c

inherit ROOM;

void create()
{
	set("short", "�ɶ�������");
	set("long", @LONG
�����Ѿ��ǳɶ������������ˣ�����ߴ�ĳɶ�������ңң
����������һ����·������������Զ�����졣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wdoor",
  "west" : "/d/chengdu_w/ccg01",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["east" : __DIR__"wdoor"]) );
	set( "close_look",@LONG
�����ǳɶ������⡣����һ����·�����ĵ���Զ�����죬��
�����ǳɶ��������ţ�������ɫ���������Ѿ������ˡ�
LONG
);
	set( "gate_name","�ɶ�����" );
*/
	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
