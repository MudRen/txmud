// Room: /d/chengdu/out_chengdu_n.c

inherit ROOM;

void create()
{
	set("short", "�ɶ�������");
	set("long", @LONG
�����Ѿ��ǳɶ����ı������ˣ�����ߴ�ĳɶ�������ңң
�������ɴ�һֱ�򱱾�����ͤ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"ndoor",
  "north" : "/d/path5/kch56",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["south" : __DIR__"ndoor"]) );
	set( "close_look",@LONG
�����ǳɶ������⡣����һ����·�����ĵ���Զ�����죬��
�Ͽ��ǳɶ��ı����ţ�������ɫ���������Ѿ������ˡ�
LONG
);
	set( "gate_name","�ɶ�����" );
*/
	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
