// Room: /u/w/wangs/b/kai148.c

inherit ROOM;

void create()
{
	set("short", "���ⶫ����");
	set("long", @LONG
������һ��ͨ����ǣ��˿��ڶ࣬��ҵ�������Թ���������
���ұ���֮�ء������ǿ���Ǽ�ʵ�Ķ����ţ���ʮ��ʿ�������
վ�ڳ��űߣ�����������������Ҵҵ����ˡ����ﲻ���̯��㣬
�಻׼������㶺���������Ե�ʮ�����ࡢ���ࡣ����һ����·
ͨ��Զ����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"edoor",
	"east" : "/d/path3/k_h1",
]));
/*
        set( "GATE_ROOM",1 );
        set( "gate_dir",(["west" : __DIR__"edoor"]) );
        set( "close_look",@LONG
������һ��ͨ����ǣ��˿��ڶ࣬��ҵ�������Թ���������
���ұ���֮�ء�������ǿ���Ķ������棬������ɫ��������
�Ѿ������ˡ�
LONG
);

        set( "gate_name","���ⶫ��" );
*/
        set("outdoors","kaifeng");
	setup();
}
