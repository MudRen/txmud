// Room: /d/guozijian/pailou.c 

inherit ROOM; 
 
void create() 
{ 
	set("short", "�����Ʒ�");
	set("long", @LONG
�����ǰ������һ�������Ʒ�������Ʒ��߰��ף������ף�
������Ѫ��ɫ���������һЩ���ƣ����ӵ���ׯ�أ���¥���ϱ�
����ֱ�д�С����Ž��󡱺͡�ѧ���ڹۡ�����������Ϊ��ɫ��
�������ܱ�ͤ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"yongdao2",
		"north" : __DIR__"shiqiao1",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}
