// Room: /d/path5/w07.c

inherit ROOM;

void create()
{
	set("short", "���׽���");
	set("long", @LONG
����������������׽��ˡ���վ�ڽ��������������ϵĽ�ˮ��
����˼����ǧ��������ȥ��һ����ԭ��������ǰ�����˽�����
�ǲ��������ˣ���˵�ǱߵĲ�������׺�������С��Щ�á���
����һ��ľ׮����������İ���һ������ͨ��������
LONG
	);
	set("item_desc",([
          "����":"
����һ����֪��ʲô�����ϵ�������������ȥʮ�ֽ�ʵ��
������ɳ�������Ƕ��ǿ���(pull)���������������紵��ɹ��
������ɫ���Եð��ڡ� \n",
]));

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"w06",
]));

        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}