// Room: /d/guozijian/yongdao1.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��");
	set("long", @LONG
������һ������ש�̳ɵ��������߳�������ݣ�ÿ������
����һ�Ű��������������ɿ������Ծ����ӣ����������м�����
����ʷ�ˣ�������ͨ��̫ѧ�ţ��������Ǽ����ţ�����������
��ͤ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"xi_jiting",
		"east" : __DIR__"dong_jiting",
		"north" : __DIR__"tx_gate",
		"south" : __DIR__"gzj_gate",
]));

	set("NORIDE","�˴�Ϊ�����Ŀ��صأ��Ĺ��½Σ��������\n");
	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}
