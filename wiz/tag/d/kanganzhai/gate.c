// gate.c

inherit ROOM;
void create()
{
        set("short", "����կ����");
        set("long", @LONG
�������˿���կ���ţ��м���Ѳ�ӵ�С�����ֵض����㣬
��������Щ��ë��կ���������裬�ߴ��կǽ������������
����Ѳ�ӡ������ߵĴ�·ֱͨկ�����һ��С·ͨ������·��
����ԥ��Ҫ��Ҫ��կһ����
LONG
);
        set("exits", ([
                "north" : __DIR__"nroad8",
                "east" : "/d/path3/k_s9",
        ]));

        set( "GATE_ROOM",1 );
        set( "gate_dir",(["north" : __DIR__"inner_gate"]) );
        set( "close_look",@LONG
�����ǿ���կ�Ĵ��ţ�ҹ����Ŷ��ǹ��ϵġ�
LONG
);
        set( "gate_name","����կ����");

        set("outdoors","path3");

        setup();
}

