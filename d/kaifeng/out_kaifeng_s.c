// Room: /u/w/wangs/b/kai116.c

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
������ǿ���ǵ��������ˣ����������ǳ����֣��е�����
��ϲɫ���еĳ������棬�����ڿ���������ҵ��̨��վ�ȽŸ���
���Ǻ����׵����鰡���кܶ���һҹ֮�䱩����Ҳ�������֮��
����ҵ���������һ������·ͨ��Զ����
LONG
	);

	set("exits", ([
  "north" : __DIR__"sdoor",
  "south" : "/d/path3/k_s1",
]));
/*
        set( "GATE_ROOM",1 );
	set( "gate_dir",(["north" : __DIR__"sdoor"]) );
        set( "close_look",@LONG
������ǿ���ǵ��������ˣ�����ߴ������ңң��������
����ɫ���������Ѿ������ˡ����ܾ����ĵģ�����һ������·
ͨ��Զ����
LONG
);
        set( "gate_name","��������" );
*/
	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
