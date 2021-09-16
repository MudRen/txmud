// Room: /d/c/sdoor.c

inherit ROOM;

void create()
{
	set("short", "�ɶ�����");
	set("long", @LONG
���������������ɶ����ϳ��ţ����ĳ�ǽ�ϰ߲��ĺۼ�
���Կ�������������ɣս�ҵ���ʷ����������Ȼ��̵������š�
�������ŵ��˴�����Ϣ����ʾ�Ž��յķ��������Ź��þ������
����ɨ����������������������ʱ����ס����������һ��������
�Ա�����һ�Ų���(bugao)��
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"out_chengdu_s",
  "north" : __DIR__"shizi",
]));

	set("item_desc", ([ /* sizeof() == 2 */
                "bugao": (: call_other, CRIME_D, "query_placard" :),
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["south" : __DIR__"out_chengdu_s"]) );
	set( "close_look",@LONG
���������������ɶ��ı����ţ�����������ʱ�䣬������
�������ˡ������ĵ�ֻ���سǵ�ʿ���ǻ������վ�����
LONG
);
	set( "gate_name","�ɶ�����" );
*/
	set("objects",([
		NPC_DIR"city_guard" : 2,
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
