// Room: /d/guozijian/chengxin.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "������");
	set("long", @LONG
�����ǳ����ã��Ǽ���ѧϰ�ĵط����������м�������վ��
�����Աߣ���ʺ͸�����һ�ᣬ����ë�����ɷ����д��������
�����Ѿ�С�гɾ͡�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"shuaixing",
]));

	setup();
	replace_program(ROOM);
}
