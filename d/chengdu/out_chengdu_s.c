// Room: /d/chengdu/out_chengdu_s.c

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
  "north" : __DIR__"sdoor",
  "south" : __DIR__"scd01",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["north" : __DIR__"sdoor"]) );
	set( "close_look",@LONG
�����ǳɶ������⡣����һ����·�����ĵ���Զ�����죬��
�����ǳɶ����ϳ��ţ�������ɫ���������Ѿ������ˡ�
LONG
);
	set( "gate_name","�ɶ�����" );
*/
	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
