// Room: /d/path5/kch18.c

inherit ROOM;

void create()
{
	set("short", "ɽϪ");
	set("long", @LONG
�������������һƬ��ɫ�����֣��������������������
�졣��Ȼ������ˮ����������ϸһ�����峺��ɽȪ��˳��ɽ����
�ʣ���·��һ����ʯ���ݴ���۳�һ̶�����ˮ�Ȱɣ��ǿ��Ǵ�
��Ȼ��ʯ�ߺ����һ������(pai)��
LONG
	);
	set("item_desc",([
	"pai":"
	east         ���ɽ
	northup      ���ɽ
\n",
	"����":"
	east         ���ɽ
	northup      ���ɽ
\n",
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"kch19",
  "northup" : __DIR__"kch17",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "��ǰ��ĵ��Σ���ͽ�����ܹ�ȥ��������ûϷ�ˡ�");
	setup();
	replace_program(ROOM);
}
