// Room: /open/k/sdoor.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������ǿ���ǵ��ϴ����ˣ��������ϴ���ϵ�����������
�����̿ͣ��е������ϲɫ���еĳ������棬�����ڿ���������
ҵ��̨��վ�ȽŸ������Ǻ����׵����鰡���кܶ���һҹ֮�䱩
����Ҳ�������֮�����ҵ�����������ı�����Ͼ�������һ
ĻĻ�������š���������ɽ�ֶ����������֡�
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"kai61",
	"north" : __DIR__"kai113",
	"east" : __DIR__"kai166",
	"south" : __DIR__"out_kaifeng_s",
]));

        set("objects",([
        __DIR__"npc/guanbing" : 2,
]));
/*
        set( "GATE_ROOM",1 );
	set( "gate_dir",(["south" : __DIR__"out_kaifeng_s"]) );
        set( "close_look",@LONG
������ǿ���ǵ������ˣ��ߴ��̵ĵĳ�����������ǰ��
������ɫ���������Ѿ������ˡ�
LONG
);
        set( "gate_name","��������" );
*/
	set("outdoors","kaifeng");

	setup();
	replace_program(ROOM);
}
