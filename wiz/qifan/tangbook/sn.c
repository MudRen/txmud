#include <ansi.h>

inherit NPC;

int ask_book(object who,string topic);
int ask_all(object who);

protected string *books = ({
"liuhua-sword",
"tang-force",
"tianchan-steps","wuying-zhang",
"tang-du",
"medicine",
});

protected string all_msg;

protected void make_book_msg()
{
        if( !all_msg )
                all_msg = "";

        foreach(string tmp in books)
                all_msg += sprintf("    %s(%s)\n", to_chinese(tmp), tmp);
}

void create()
{
        set_name("��ū", ({ "shu nu","nu","sn" }) );

        set(NO_KILL, 1);
        set("class","tangmen");
        set("title","�����˲�����");

        set("gender", "����" );
        set("age", 13);
        set("long", "����һλӢ�������ꡣ\n");
        set("attitude", "peaceful");
        set("inquiry",([
        "book" : (: ask_all :),
        WILDCARD : (: ask_book :),
]));
 
        set("combat_exp", 100000);
        set("str", 67);
        set("max_kee",1200);
        set("kee",1200);
        set("max_gin",1200);
        set("gin",1200);
        set("max_sen",1200);
        set("sen",1200);
        set("force", 1200);
        set("max_force", 1200);
        set("atman", 1200);
        set("max_atman", 1200);
        set("mana", 1200);
        set("max_mana", 1200);
        set("force_factor", 100);

        set_skill("unarmed",260);
        set_skill("dodge",260);
        set_skill("parry",250);
        set_skill("force",200);

        make_book_msg();
        setup();
 
        carry_object(ARMOR_DIR"cloth")->wear();
}

int ask_book(object who,string topic)
{
        int n;
        string file;
        object book_ob;

        if(!who
        || (who->query("class") != "tangmen")
        || !stringp(topic)
        || !environment()
        || (base_name(environment()) != query("startroom")) )
                return 0;

        if( ((n = member_array(topic,books)) == -1)
        && ( (n = member_array(topic,map_array(books,(: to_chinese :)))) == -1))
                return 0;
 
        file = sprintf(__DIR__"obj/%s_book",books[n]);
        if(file_size(file+".c") <= 0 || !book_ob = new(file))
                return 0;

        message_vision(sprintf("$Nת���������ó�һ��%s������$n��\n",book_ob->name()),
                this_object(),who);
        book_ob->move(who);

        command("say ��Щ����͵͵�Ŀ��ɣ����ó�ȥ����֪���ˡ�\n");
        return 1;
}

int accept_object(object who,object ob)
{
        if(!who || !ob)
                return 0;

        if(ob->is_tangmen_book())
        {
                call_out("destruct_book",1);
                return 1;
        }
        else
                return 0;
}

void destruct_book()
{
        int i,n;
        object *inv;

        inv = all_inventory(this_object());
        if(!n = sizeof(inv))
                return;

        for(i=0;i<n;i++)
                if(inv[i]->is_tangmen_book())
                        destruct(inv[i]);
}

int ask_all(object who)
{
        if(who->query("family/family_name") != "��������")
                return 0;

        tell_object(who, sprintf("\n�������ֻ����Щ���Լ���д�Ļ����飬�߼���Ҫ����ү������źá�\n%s\n", all_msg));
        return 1;
}
