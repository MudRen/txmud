// Room: /d/guozijian/yilun.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "������");
	set("long", @LONG
�����������ã��ǹ��Ӽ��в���ĵط����������������ʷ
�ƾã��������ղص��鼮Ҳ�Ƚ�ȫ��������е÷ǳ����룬����
һ����Ⱦ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"up" : __DIR__"yilunup",
		"south" : __DIR__"yongdao4",
]));

	setup();
	replace_program(ROOM);
}
