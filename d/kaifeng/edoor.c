// Room: /open/k/edoor.c

inherit ROOM;

void create()
{
	set("short", "���ⶫ��");
	set("long", @LONG
������ǿ���Ķ������ˣ�������һ��ͨ����ǣ��˿��ڶ࣬
��ҵ�������Թ��������Ǳ��ұ���֮�ء���ʵ�ĳ�¥�����ɶ�ߣ�
��ʮ��ʿ�������վ�ڳ��űߣ�����������������Ҵҵ����ˡ�
���ﲻ���̯��㣬�಻׼������㶺���������Ե�ʮ�����ࡢ
���ࡣ
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai147",
  "east" : __DIR__"out_kaifeng_e",
]));


        set("objects",([
        __DIR__"npc/guanbing" : 2,
]));
/*
        set( "GATE_ROOM",1 );
        set( "gate_dir",(["east" : __DIR__"out_kaifeng_e"]) );
        set( "close_look",@LONG
������ǿ���Ķ������ˣ�������һ��ͨ����ǣ��˿��ڶ࣬
��ҵ�������Թ��������Ǳ��ұ���֮�ء���ʵ�ĳ�¥�����ɶ�ߡ�
LONG
);
        set( "gate_name","���ⶫ��" );
*/
	set("outdoors","kaifeng");

	setup();
	replace_program(ROOM);
}
