// Room: /open/k/ndoor.c

inherit ROOM;

void create()
{
	set("short", "���ⱱ��");
	set("long", @LONG
��ΰ�ı����ǿ���ǵ����ţ����Ա���������������������
������ر�׳�ۡ������Ĵ���ӳ�����ֱ����Զ����һ�Ӷӵ�ʿ
�����������¥���߹������ﲻ���̯��㣬�಻׼������㶺
���������Ե�ʮ�����ࡢ���ࡣ
LONG
	);

	set("exits", ([
  "south" : __DIR__"kai92",
  "north" : __DIR__"out_kaifeng_n",
]));

        set("objects",([
        __DIR__"npc/guanbing" : 2,
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["north" : __DIR__"out_kaifeng_n"]) );
	set( "close_look",@LONG
��ΰ�ı����ǿ���ǵ����ţ����Ա���������������������
������ر�׳�ۡ�������ɫ���������Ѿ������ˡ�
LONG
);
        set( "gate_name","���ⱱ��" );
*/
	set("outdoors","kaifeng");

	setup();
	replace_program(ROOM);
}
