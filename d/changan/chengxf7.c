// Room: chengxf7.c

inherit ROOM;

void create()
{
        set("short", "�鷿");
	set("long", @LONG
�����ǳ���ة�ฮ���鷿��һ������Ϳ���ǽ�Ϲ���ة����
�ʻ���һ������ͼ������ɾ����£�������һ�������ıڵ����
�ϰ����ˣ������鼮�����Ϸ������ķ��ı�������������������
���ˡ�
LONG
	);

        set("exits", ([
  "west" : __DIR__"chengxf6",
]));
        setup();

	replace_program(ROOM);
}