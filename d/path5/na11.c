// Room: /d/path5/na11.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����һ������С·��·�����߳��ŸߵͲ���Ĺ�ľ���㲻��
������Ҫ��һ��С�ı����˾Ͳ�ֵ�ˡ�С·��������������
�ϣ�������Ҳ�������ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"na10",
  "north" : __DIR__"na12",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
