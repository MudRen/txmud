// Room: /d/guozijian/zhengyi.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "������");
	set("long", @LONG
�����������ã��Ǽ���ѧϰ�ĵط�����������Ҫ���޵��У�
��͢�Ĺ�Աÿ��һ��ʱ�䣬�͵�����������һ��ʱ�䡣�����Ա�
�ļ���������ѧϰ�ȵ۵���������Ȼû�д��ٸ���������ʦ˵��
�Ŀ����̶ȣ�����Ҳ�Ƕ�Ʒ���ϡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"xiudao",
]));

	setup();
	replace_program(ROOM);
}
