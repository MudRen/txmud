// Room: /d/chengdu/out_chengdu_e.c

inherit ROOM;

void create()
{
	set("short", "�ɶ�������");
	set("long", @LONG
�����Ѿ��ǳɶ����Ķ������ˣ�����ߴ�ĳɶ�������ңң
����������һ����·������������Զ�����졣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"edoor",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["west" : __DIR__"edoor"]) );
	set( "close_look",@LONG
�����ǳɶ������⡣����һ����·�����ĵ���Զ�����죬��
�����ǳɶ��Ķ����ţ�������ɫ���������Ѿ������ˡ�
LONG
);
	set( "gate_name","�ɶ�����" );
*/
	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
