// Room: /d/path5/w01.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ����ƽ��Щ��С·��·����Щ��б��·�����߶��ǰ�
�˸ߵ��Ӳݣ�����һЩ��֪����Ұ������������Щ�������㲻��
�üӿ��˽Ų����ɴ�������ȥ������Խ��Խ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"kch03",
  "westup" : __DIR__"w02",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
