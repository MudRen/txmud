// dt_fenduo_2.c

inherit ROOM;

void create()
{
        set("short", "�᷿");
        set("long", @LONG
��һ����䷿��Ͳ������棺������ʲô�᷿������������
������Ҫ�������ˣ����������һ����Ȼ���ƿ���ֱ�Ӿ���¶��
���ˡ����Ｘ��ʲô�Ҿ�Ҳû�У�ֻ�������ò����Ĵ���
LONG
);

        set("no_clean_up", 1);
        set("sleep_room", 1);
        set("exits", ([
                "south" : __DIR__"dt_fenduo",
        ]));

        set("item_desc", ([
                "��" : "���ſ������ƾɵĴ��ƺ�������ʵ�úܡ�\n",
        ]));

        setup();
}
