// Room: /open/k/wdoor.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������һ��ͨ����ǣ��˿��ڶ࣬��ҵ�������Թ���������
���ұ���֮�ء���ʵ�ĳ�¥�����ɶ�ߣ���ʮ��ʿ�������վ��
���űߣ�����������������Ҵҵ����ˡ������ڲ�ĳ�ǽ������
��һ�Ÿ�ʾ(gaoshi)�����˺ܶ���פ��Χ�ۡ�
LONG
	);

	set("exits",([
	"west" : __DIR__"out_kaifeng_w",
	"east" : __DIR__"kai2",
]));

        set("objects",([
        __DIR__"npc/guanbing" : 2,
]));
/*
        set( "GATE_ROOM",1 );
        set( "gate_dir",(["west" : __DIR__"out_kaifeng_w"]) );
        set( "close_look",@LONG
������һ��ͨ����ǣ��˿��ڶ࣬��ҵ�������Թ���������
���ұ���֮�ء�������ǿ���������ˣ�������ɫ����������
�������ˡ�
LONG
);
        set( "gate_name","��������" );
*/
	set("outdoors","kaifeng");
	setup();
}
