// treasure.c
#include <ansi.h>
#include <weapon.h>

#ifndef __TREASURE__
#define __TREASURE__

#define TR_ATTRIBUTE    __DIR__"tr_attribute"
#define TR_TYPE                 __DIR__"tr_type"
#define TR_A0T0IN               __DIR__"tr_a0t0in"
#define TR_A0T1IN               __DIR__"tr_a0t1in"
#define TR_A3T0IN               __DIR__"tr_a3t0in"
#define TR_QUERY                __DIR__"tr_query"

//#define TR_SAVE_DIR           DATA_DIR "treasure/"
#define TR_SAVE_DIR             "/wiz/aiai/treasure/save"


#define TR_MAX_DROPS    8       // ��������������Ϊ = max/2
#define TR_MAX_LEVEL    8       // tr �������
#define TR_GEM                  3       // tr ��ʯ������id
#define TR_CHARM                4       // tr ����������id

#endif

//              set("actions", (: WEAPON_D, "query_action" :) );
///////////////////////////////////////////////////////
// ��tr object���Ӽ�ֵ
void tr_add_value(object ob, int val);

// ��tr object���ۣ��� temp �� "my_value" ����
void tr_set_value(object ob, int val);

// ����trʵ���Ļ�����Ϣ
void tr_copy_basic_info(object ob, int attr, int type, int level, int instance);

// ��ֵ���΢����str��ʽ����Ϊ "123=456" 
string tr_adjust(string str);

// query attribute mapping
mapping tr_querya(object ob);
// query type mapping
mapping tr_queryt(object ob);
// query level = tr_getl
int tr_queryl(object ob);
// query instance mapping
mapping tr_queryi(object ob);

// ȡ��tr����Ϣ�������� tr ��ʱ��ʹ��
int tr_geta(object ob);
int tr_gett(object ob);
int tr_getl(object ob);
int tr_geti(object ob);

// ��tr object���Ӽ�ֵ
void tr_add_value(object ob, int val);

// �鿴ʱ����Ϣ
int do_look(string str);

// ���ɱ���ob
int tr_make(object ob);

////////////////////////////////////////////////////////////////////////////////
// ������һЩ���õĲ�������

// ��tr object���Ӽ�ֵ
void tr_add_value(object ob, int val)
{
        ob->add_temp("my_value", val);
        if ((int)ob->query_temp("my_value", 1)<0)
                ob->set_temp("my_value", 0);
}

// ��tr object���ۣ��� temp �� "my_value" ����
void tr_set_value(object ob, int val)
{
        ob->add_temp("my_value", val);
        if ( !ob->query_temp("my_value") ||
                to_int(ob->query_temp("my_value", 1))<0 )
                ob->set("value", 1);
        else ob->set("value", to_int(ob->query_temp("my_value", 1)));
}

////////////////////////////////////////////////////////////////////////////////
// query attribute mapping
mapping tr_querya(object ob)
{
        return TR_ATTRIBUTE->query((int)ob->query("tr_info/a", 1));
}

// query type mapping
mapping tr_queryt(object ob)
{
        return TR_TYPE->query((int)ob->query("tr_info/a", 1),
                                                  (int)ob->query("tr_info/t", 1));
}

// query level
int tr_queryl(object ob)
{
        return (int)ob->query("tr_info/l", 1);
}

// query instance mapping
mapping tr_queryi(object ob)
{
        int ta, tt;
        mapping ap;

        ta=(int)ob->query("tr_info/a", 1);
        tt=(int)ob->query("tr_info/t", 1);
        switch ( ta )
        {
        case 0:
                switch ( tt )
                {
                case 0:
                        return TR_A0T0IN->query((int)ob->query("tr_info/l", 1),
                                                         (int)ob->query("tr_info/i", 1));
                        break;
                case 1:
                        return TR_A0T1IN->query((int)ob->query("tr_info/l", 1),
                                                         (int)ob->query("tr_info/i", 1));
                        break;
                default:        // ����attr 0 /type 0
                        return TR_A0T0IN->query((int)ob->query("tr_info/l", 1),
                                                         (int)ob->query("tr_info/i", 1));
                        break;
                }
                break;
        case 3:    // ��ʯ
                switch ( tt )
                {
                case 0:
                        return TR_A3T0IN->query((int)ob->query("tr_info/l", 1),
                                                         (int)ob->query("tr_info/i", 1));
                        break;
                default:
                        return TR_A3T0IN->query((int)ob->query("tr_info/l", 1),
                                                         (int)ob->query("tr_info/i", 1));
                        break;
                }
                break;
        default:
                switch ( tt )
                {
                default:        // ����attr 0 /type 0
                        return TR_A0T0IN->query((int)ob->query("tr_info/l", 1),
                                                         (int)ob->query("tr_info/i", 1));
                        break;
                }
                break;
        }

        return ap;
}

////////////////////////////////////////////////////////////////////////////////
// ȡ��tr����Ϣ�������� tr ��ʱ��ʹ��
int tr_geta(object ob)
{
        return (int)ob->query_temp("tr_info/a", 1);
}

int tr_gett(object ob)
{
        return (int)ob->query_temp("tr_info/t", 1);
}

int tr_getl(object ob)
{
        return (int)ob->query_temp("tr_info/l", 1);
}

int tr_geti(object ob)
{
        return (int)ob->query("tr_info/i", 1);
}

////////////////////////////////////////////////////////////////////////////////
// ��ֵ���΢����str��ʽ����Ϊ "123=456" 
// 100֮����%�п���ȫ��0
// ���Ա仯��������ֵ -2 to 2
// >100�����ðٷֱȵ�����ֵ
// �仯����Ϊ -2% to 2%
string tr_adjust(string str)
{
        int id=0, num=0, tp;
        sscanf(str, "%d=%d", id, num);
        tp=num;
        if (num>-100 && num<100) num+=2-random(5);
        else num+=random(num/25)-num/50;
        if ((tp<0 && num>-1) || (tp>0 && num<1)) tp=num;
        return sprintf("%d=%d", id, num);
}
////////////////////////////////////////////////////////////////////////////////
// ���������˺�
//varargs void tr_set_damage(int damage, object ob)
void tr_set_damage(object ob, int damage)
{
        ob->set("weapon_prop/damage", damage);
}

////////////////////////////////////////////////////////////////////////////////
// �ж�player�Ƿ�����װ��/ʹ����������
int tr_on_limit(object me, string lim)
{
        int num=0;
        int id, min;
        mapping ap;

        if (!me || living(me)) me=this_player();

        sscanf(lim, "%d=%d", id, min);
        ap=TR_QUERY->query_limit(id);

        if (!ap) return 0;

        switch (ap["type"])
        {
        case 0: num=(int)me->query(ap["id"], 1);        break;
        case 1: num=me->query_str();    break;
        case 2: num=me->query_cor();    break;
        case 3: num=me->query_int();    break;
        case 4: num=me->query_con();    break;
        case 5: num=me->query_kar();    break;
        case 6: num=me->query_per();    break;
        default:        // -1 ( or <0 )
                num=(int)me->query_skill(ap["id"], 1);
                break;
        }

        if (num<min) return 0;

        return 1;
}

////////////////////////////////////////////////////////////////////////////////
// ����trʵ���еĻ�������
void tr_copy_name(object ob)
{
        mapping ap, api;
        ap=tr_queryt(ob);
        api=tr_queryi(ob);
        if (ap["random_id"])
                if (api["id"]!=ap["id/0"])
                        ob->set_name(api["name"], ({api["id"], ap["id/0"]}));
                else ob->set_name(api["name"], ({api["id"]}));
        else if (api["id"]!=ap["id"]) 
                ob->set_name(api["name"], ({api["id"],ap["id"]}));
        else ob->set_name(api["name"], ({api["id"]}));
}

////////////////////////////////////////////////////////////////////////////////
// �ָ�tr�еı����ص�����
void tr_revert_name(object ob)
{
        mapping ap;//, api;
        string t_name, t_id;
        t_name=ob->query("hide_name");
        t_id=ob->query("hide_id");
        ap=tr_queryt(ob);
        //api=tr_queryi(ob);
        if (ap["random_id"])
                if (t_id!=ap["id/0"])
                        ob->set_name(t_name, ({t_id, ap["id/0"]}));
                else ob->set_name(t_name, ({t_id}));
        else if (t_id!=ap["id"]) 
                ob->set_name(t_name, ({t_id,ap["id"]}));
        else ob->set_name(t_name, ({t_id}));
}

////////////////////////////////////////////////////////////////////////////////
// ����trʵ���еĻ���װ��/ʹ������      ������ while ȡ mapping �е� mapping
// is_random=1��ʾ��������ֵ΢��仯������Ϊ 2%
void tr_copy_limit(object ob, int is_random)
{
        int i=0;
        mapping ap=tr_queryi(ob);

        if (ap["limit/0"])
        {
                while ( ap["limit/"+sprintf("%d", i)] )
                {
                        ob->set("gift_limit/"+sprintf("%d",i),
                                is_random ? tr_adjust(ap["limit/"+sprintf("%d",i)]) : 
                                ap["limit/"+sprintf("%d",i)] );
                        i++;
                }
        }
}

////////////////////////////////////////////////////////////////////////////////
// ����trʵ���еĻ����������ԣ�������ȡ����instance mapping��Ϊ���Ժ�׷��׺��
mapping tr_copy_gift(object ob, int is_random)
{
        int i=0;
        mapping ap=tr_queryi(ob);

        if (ap["gift/0"])
        {
                while ( ap["gift/"+sprintf("%d", i)] )
                {
                        // ������Ա�־Ҳ���ƣ�����Ǽ���ı�������������
                        // ������ԣ������δ����ı�����ڼ����ʱ���������
                        if (strsrch(ap["gift/"+sprintf("%d", i)], "-1=") != -1)
                                ob->set("gift_apply/"+sprintf("%d",i),
                                        ap["gift/"+sprintf("%d",i)] );
                        else
                                ob->set("gift_apply/"+sprintf("%d",i),
                                        is_random ? tr_adjust(ap["gift/"+sprintf("%d",i)]) : 
                                        ap["gift/"+sprintf("%d",i)] );
                        i++;
                }
        }
        return ap;
}

////////////////////////////////////////////////////////////////////////////////
// ׷��һ��tr�������ԣ�����gift mapping��Ϊ���Ժ�׷��׺��
// key_word=׷�ӵ��ĸ�mapping�ϣ�αװ��ʱ����
// appointed=-1 ��ʾ���ѡ������
// appointed>=0 ��ʾָ������
// is_random ��ʾ�Ƿ��Ĭ��ֵ���΢�������Ѿ��Ѿ��е����Ը��ӵ�����
// "-1=" ��־����ɾ����look tr��ʱ�򲻽�"-1="ת��Ϊ��������
// ����ʱ��ÿ����del ob ������gift����tr_copy_gift()���ƻ���
//     Ȼ�����ô˺��������������
mapping tr_add_gift(object ob, string key_word,
                                        int is_random, int appointed)
{
        int i=0, k=0, n, gift_id;
        string str;
        mapping ap;

        if (appointed>=0) gift_id = appointed;
        else if ((int)ob->query("tr_info/l", 1) > TR_MAX_LEVEL/2)
                gift_id = random(TR_QUERY->query_gift_total());
        else    // �ͼ����tr�������ȡ���߼�����
                gift_id = to_int(random(TR_QUERY->query_gift_total())/2+1);

        ap=TR_QUERY->query_gift( gift_id );
        //printf(WHT"DEBUG: gift id %d\n"NOR, gift_id);
        //printf(WHT"DEBUG: sizeof ap %d\n"NOR, sizeof(ap));
        sscanf(ap["gift"],"%*s=%d", n); // ȡ��Ĭ��ֵ

        // �ޱ�־
        if (!ob->query(key_word)) 
        {
                ob->set(key_word+"/0", is_random ?
                        tr_adjust(sprintf("%d=%d",gift_id,n))
                        : sprintf("%d=%d",gift_id,n));
        }
        else
        {
                while ( ob->query(key_word+"/"+sprintf("%d", i)) )
                {
                        sscanf(ob->query(key_word+"/"+sprintf("%d", i)), 
                                "%d=%*d", k);
                        if (k==gift_id)
                        {
                                //printf(WHT"DEBUG: same gift is %d\n"NOR, k);
                                sscanf(ob->query(key_word+"/"+sprintf("%d", i)), 
                                "%*d=%d", k);                           
                                n+=k;
                                break;
                        }
                        i++;
                }
                str=tr_adjust(sprintf("%d=%d", gift_id, n));
                ob->set(key_word+"/"+sprintf("%d", i), 
                        is_random ?
                        tr_adjust(sprintf("%d=%d",gift_id,n))
                        : sprintf("%d=%d",gift_id,n));
        }
        
        tr_add_value(ob, (gift_id+1)*
                ((int)ob->query("tr_info/l",1)+1)*
                100+random((gift_id+1)*100));

        return ap;
}

////////////////////////////////////////////////////////////////////////////////
// ����һ����������׷��׺����gift��tr_add_gift()���ص�gift mapping
void tr_add_namefix(object ob, mapping gift)
{
        int i=1;
        string str=ob->name(), str_id;
        mapping ap=tr_queryi(ob);
        mapping type=tr_queryt(ob);

        if (gift["pre_prefix"])         // ��ǰ׺
        {
                if (!ap["prefix"]) return;      // instance������׷��ǰ׺
                else if ((int)ob->query_temp("prefix", 1)>=ap["prefix"])
                        return;         // ����instance���׺��
                else if (ob->query_temp("prefix"))      // ����ǰ׺
                {
                        // �����ʱ׺��¼�����Ƿ�����ͬ��׺
                        while (ob->query_temp("pre_name/"+sprintf("%d", i)))
                        {
                                if (ob->query_temp("pre_name/"+sprintf("%d", i))
                                        == gift["name"])
                                        return;
                                i++;
                        }
                        if (gift["pre_prefix"]=="none") return;  // ��׺
                        str=gift["name"]+gift["pre_prefix"]+str;
                        str_id=gift["id"]+"_"+ob->query("id");
                }
                else
                {
                        if (gift["pre_surfix"]=="none") return;  // ��׺
                        // �������׺����
                        if (random(100)<80)
                                str=gift["name"]+gift["pre_surfix"]+str;
                        else if (random(100)>60) str=gift["name"]+"��"+str;
                        // "��"����˸�ģ�������һ��Ч��
                        //else str=gift["name"]+ESC+"[5m"+"��"+NOR+str;
                        else str=gift["name"]+"��"+str;
                        //else str=gift["name"]+str;
                        // ������id, �������ָ�ʽ��������һ��
                        // ��ʽ1        abc def sword of xyz
                        // ��ʽ2        abc_def sword_of_xyz
                        // ��ʽ3        abc-def sword-of-xyz    // ���������
                        //str_id=gift["id"]+" "+ob->query("id");
                        str_id=gift["id"]+" "+ob->query("id");
                        //str_id=gift["id"]+"-"+ob->query("id");
                }
                // ���¸�tr����(���ϱ����͵�ͨ��id)
                if (type["random_id"])
                        if (str_id!=type["id/0"])
                                ob->set_name(str, ({str_id, type["id/0"]}));
                        else ob->set_name(str, ({str_id}));
                else if (str_id!=type["id"])
                        ob->set_name(str, ({str_id, type["id"]}));
                else ob->set_name(str, ({str_id}));
                // д����ʱ׺
                ob->add_temp("prefix", 1);
                ob->set_temp("pre_name/"+
                        sprintf("%d",(int)ob->query_temp("prefix", 1)),
                        gift["name"]);
        }
        else if (gift["sur_prefix"])    // �Ӻ�׺
        {
                if (!ap["surfix"]) return;      // instance������׷��ǰ׺
                else if ((int)ob->query_temp("surfix", 1)>=ap["surfix"])
                        return;         // ����instance���׺��
                else if (ob->query_temp("surfix"))      // ���к�׺
                {
                        // �����ʱ׺��¼�����Ƿ�����ͬ��׺
                        while (ob->query_temp("sur_name/"+sprintf("%d", i)))
                        {
                                if (ob->query_temp("sur_name/"+sprintf("%d", i))
                                        == gift["name"])
                                        return;
                                i++;
                        }
                        if (gift["sur_surfix"]=="none") return;  // ��׺
                        str=str+gift["sur_surfix"]+gift["name"];
                        str_id=ob->query("id")+"_"+gift["id"];
                }
                else
                {
                        if (gift["sur_prefix"]=="none") return;  // ��׺
                        // �������׺����
                        if (random(100)<80)
                                str=str+gift["sur_prefix"]+gift["name"];
                        else if (random(100)>60) str=str+"��"+gift["name"];
                        // "��"����˸�ģ�������һ��Ч��
                        //else str=str+ESC+"[5m"+"��"+NOR+gift["name"];
                        else str=str+"��"+gift["name"];
                        str_id=ob->query("id")+"'s "+gift["id"];
                }
                // ���¸�tr����(���ϱ����͵�ͨ��id)
                if (type["random_id"])
                        if (str_id!=type["id/0"])
                                ob->set_name(str, ({str_id, type["id/0"]}));
                        else ob->set_name(str, ({str_id}));
                else if (str_id!=type["id"])
                        ob->set_name(str, ({str_id, type["id"]}));
                else ob->set_name(str, ({str_id}));
                // д����ʱ׺
                ob->add_temp("surfix", 1);
                ob->set_temp("sur_name/"+
                        sprintf("%d",(int)ob->query_temp("surfix", 1)),
                        gift["name"]);
        }
}

////////////////////////////////////////////////////////////////////////////////
// ����tr�ı�ʯ�׶���ʵ��trһ��û�ñ���Ƕ��ʯ
void tr_copy_gem(object obj)
{
        int gems,i;
        mapping ap=tr_queryi(obj);

        if (!ap["gems"]) return;        // �޿�

        gems=ap["gems"];
        if (ap["gems"]==-1)     gems=random(3); // max 2 random gems
        if (!ap["gems"]) return;        // �����޿�
        if (gems) obj->set("tr_info/gems", gems);
        for (i=0;i<gems;i++)
                obj->set("gift_gem/"+sprintf("%d", i)+"/name", "none");
        // ��ʱ���ѿ׶�����ʾ��name��
        //obj->set( "name", ob->name()+"("+sprintf("%d", gems)+")" );
}

////////////////////////////////////////////////////////////////////////////////
// ����ʯ����tr�ı�ʯ�׶���n�Ǳ�ʯid����
// ����>=0��ʾ�ɹ�������Ƕ��λ�ã�-1��ʾû�п׻����Ѿ�����
int tr_insert_gem(object ob, int n)
{
        int i=0;
        //mapping ap=tr_queryi(ob);
        if (!ob->query("tr_info/gems")) return -1;
        while ( ob->query("gift_gem/"+sprintf("%d",i)) )
        {
                if ( (int)ob->query("gift_gem/"+sprintf("%d",i), 1)==-1 )
                {
                        ob->set("gift_gem/"+sprintf("%d", i), n);
                        // ������Ӧ���ԣ���tr_add_gift()����
                        return n;
                }
                i++;
        }
        return -1;      // already full
}

////////////////////////////////////////////////////////////////////////////////
// 0 ��ɫ   1 �\�׻�ɫ   2 ��ɫ   3 ��ɫ   4 ��ɫ   5 ��ɫ   6 ����   7 ��ɫ
// ���ݼ���������ɫ��is_random=0��ʾ�������-2 to 2
void tr_set_color(object ob, int is_random)
{
        int lv=(int)ob->query("tr_info/l", 1), ta=0, tb;
        string tp, str=ob->query("hide_name");
        mapping ap;

        if (is_random) lv+=2-random(5);
        if (lv>7) lv=7;
        if (lv<0) lv=0;

        ap=tr_queryt(ob);
        if (ap["type"]=="gem")  // ��ʯ��ɫ���⴦��
        {
                if (lv<4) tp=ap["color/0"]+str+NOR;
                else tp=ap["color/1"]+str+NOR;
                ob->set("name", tp);
                return;
        }

        // ����������ɫЧ���Ľ��������������
        ta=0;
        if (random(100)>82)
        {
                tp=ESC+"[4m";
                tr_add_value(ob, random(1000)+1000);
                ta=1;
        }
        if (random(100)>84)
        {
                if (ta) tp+=ESC+"[5m";
                else tp=ESC+"[5m";
                tr_add_value(ob, random(2000)+2000);
                ta=1;
        }
        if (random(100)>90)
        {
                if (ta) tp+=ESC+"["+sprintf("%d", random(7)+41)+";" ;
                else tp=ESC+"["+sprintf("%d", random(7)+41)+";" ;
                tr_add_value(ob, random(3000)+3000);
                ta=2;
        }
        
        if (!ta) tp=ESC+"[";
        else if (ta==1) tp+=ESC+"[";
        
        tb=ta;
        ta=random(2);

        switch (lv)
        {
        // ��   13m             21m
        case 0: tp = (ta? tp+"21m" : tp+"13m"); break;
        //�\�׻�        47;10m  18m             17m             25m;    
        case 1: switch (0)//random(4))
                {
                case 1: tp += "18m"; break;
                case 2: tp += "17m"; break;
                case 3: tp += "25m"; break;
                case 0: 
                        {
                                if (tb!=2)
                                        tp += "47;10m";
                                else
                                        tp += "10m";
                        }
                } break; 
        // ��   11m             19m
        case 2: tp = (ta? tp+"19m" : tp+"11m"); break;
        // ��   15m             23m
        case 3: tp = (ta? tp+"23m" : tp+"15m"); break;
        // ��   14m             22m
        case 4: tp = (ta? tp+"22m" : tp+"14m"); break;
        // ��   24m
        case 5: tp += "24m";    break;
        // ���� 16m
        case 6: tp += "16m";    break;
        // ��   20 
        case 7: tp += "20m";    break;
        }
        tp+=str+NOR;
        ob->set("name", tp);
}

////////////////////////////////////////////////////////////////////////////////
// ����δ����tr��ĳЩ��ֵ
void tr_pretend(object ob)
{
        int i, j, k;
        mapping type, ap;
        string t_name, t_id, t_long, str;
        string ori_name, ori_id;

        //ori_name=ob->name();  // ����ԭʼname/id
        //ori_id=ob->query("id");
        ori_name=ob->query("hide_name");        // ����ԭʼname/id
        ori_id=ob->query("hide_id");

        type=tr_queryt(ob);
        i=0;    // ȡ�����name
        if (type["random_name"])
        {
                while ( type["name/"+sprintf("%d", i)] ) i++;
                t_name=type["name/"+sprintf("%d", random(i))];
        }
        else t_name=type["name"];
        i=0;    // ȡ�����id
        if (type["random_id"])
        {
                while ( type["id/"+sprintf("%d", i)] ) i++;
                t_id=type["id/"+sprintf("%d", random(i))];
        }
        else t_id=type["id"];
        i=0;    // ȡ�����long
        while ( type["long/"+sprintf("%d", i)] ) i++;
        t_long=type["long/"+sprintf("%d", random(i))];
        ob->set_name(t_name,({t_id}));
        ob->delete("pretend_gift");             // ɾ���ϴεļ�gift
        ob->delete_temp("pre_name");
        ob->delete_temp("sur_name");
        ob->delete_temp("prefix");
        ob->delete_temp("surfix");
        for (i=0;i<random(3);i++)       // ���׷��׺��
        {
                ap=TR_QUERY->query_random_namefix(-1);
                tr_add_namefix(ob, ap);
                if (random(10)>6)
                {
                        j=0;
                        while (ob->query("gift_apply/"+sprintf("%d", j)))
                        {
                                if (random(10)>6)       // ����ʵ�����г�ȡһ��
                                {
                                        k=0;
                                        while (ob->query("pretend_gift/"+sprintf("%d", k)))
                                                k++;
                                        str=ob->query("gift_apply/"+sprintf("%d", j));
                                        if (strsrch(str,"-1=")==-1)
                                                ob->set("pretend_gift/"+sprintf("%d", k), str);
                                        break;
                                }
                                j++;
                        }
                        if (!j) tr_add_gift(ob, "pretend_gift", 1, -1);
                }
                else
                {
                        tr_add_gift(ob, "pretend_gift", 1, -1);
                }
        }
        //if (!ob->query("hide_name"))
        //{
                ob->set("hide_name", ob->name());       // ������ʱ����
                ob->set("hide_id", ob->query("id"));
        //}
        tr_set_color(ob, 1);    // δα����������ɫ
        ob->set("value", (int)ob->query_temp("my_value", 1)/10+
                random((int)ob->query_temp("my_value", 1)/10));
        // ����name/id/value/damage
        //if (!ob->query("hide_name"))
        //{
                ob->set("hide_name", ori_name);
                ob->set("hide_id", ori_id);
                ob->set("hide_value", (int)ob->query_temp("my_value", 1));
        //}
        if (ob->query("weapon_prop/damage"))
        {
                i=(int)ob->query("weapon_prop/damage", 1);
                ob->set("hide_damage", i);
                tr_set_damage(ob, to_int(random(i/2)+i/2));
        }
        ob->set("long", replace_string(t_long, "ch", ob->name()));
        ob->delete_temp("pre_name");
        ob->delete_temp("sur_name");
        ob->delete_temp("prefix");
        ob->delete_temp("surfix");
        ob->delete_temp("my_value");
}

////////////////////////////////////////////////////////////////////////////////
// ��ԭδ������tr
void tr_revert(object ob)
{
        //if (ob->query("tr_ident")) return;    // �Ѿ��Ǳ����������

        ob->set("tr_ident", 1);
        tr_revert_name(ob);             // �ָ�����
        tr_set_color(ob, 0);
        ob->set("value", (int)ob->query("hide_value", 1));
        if (ob->query("weapon_prop/damage"))
        {
                tr_set_damage(ob, (int)ob->query("hide_damage", 1));
        }
        ob->set("long", replace_string(tr_queryi(ob)["long"], "ch", ob->name()));
        ob->delete("pretend_gift");
}

////////////////////////////////////////////////////////////////////////////////
// ����tr green set��������ֵ(�������ɫ��װ)
void tr_copy_green_set(object ob)
{
        
}

////////////////////////////////////////////////////////////////////////////////
// ����trʵ���еĻ�����Ϣ       ����ǰ��
void tr_copy_basic_info(object ob, 
                                                int mf_attr, int mf_type, 
                                                int mf_level, int mf_instance)
{
        int i, num;
        mapping ap, type, attr;
        string sname;

        ob->set("tr_info/a", mf_attr);
        ob->set("tr_info/t", mf_type);
        ob->set("tr_info/l", mf_level);
        ob->set("tr_info/i", mf_instance);

        ap=tr_queryi(ob);
        type=tr_queryt(ob);
        attr=tr_querya(ob);

        tr_copy_name(ob);
        ob->set_weight(ap["weight"]);
        tr_add_value(ob, to_int(random(ap["value"])+ap["value"]/2));
        ob->set("tr_ident", ap["ident"]);

        tr_copy_limit(ob,1);
        tr_copy_gift(ob,1);

        if (strsrch(ap["gift/0"], "-1=") != -1)
        {
                sscanf(ap["gift/0"], "-1=%d", num);
                if (num)
                        for (i=0; i<=random(num); i++)
                        {
                                tr_add_namefix(ob, tr_add_gift(ob, "gift_apply", 1, -1));
                        }
        }

        tr_copy_gem(ob);
        tr_copy_green_set(ob);

        if (ob->query("weapon_prop/damage"))
                tr_set_damage(ob, ap["power"]);

        if (ap["autoload"])
                ob->set("tr_info/autoload", ap["autoload"]);

        ob->set("material", ap["material"]);
        ob->set("hide_name", ob->name());
        ob->set("hide_id", ob->query("id"));

        if (ap["sprite"]!=-1)
                ob->set("tr_sprite", ap["sprite"]);

        if (!ap["ident"]) 
        {
                tr_pretend(ob);
        }
        else
        {
                tr_set_color(ob, 0);
                ob->set("value", (int)ob->query_temp("my_value", 1));
                ob->set("long", replace_string(ap["long"], "ch", ob->name()));
                ob->delete_temp("my_value");
                ob->delete_temp("prefix");
                ob->delete_temp("pre_name");
                ob->delete_temp("surifx");
                ob->delete_temp("sur_name");
        }
        if (ob->query("tr_info/autoload"))
        {
                sname=(tr_queryt(ob)["random_id"] ?
                        tr_queryt(ob)["id/0"]:
                        tr_queryt(ob)["id"]);
                ob->set("tr_info/file", 
                        sprintf(TR_SAVE_DIR "%c/%s%d", sname[0], sname, time()));
                ob->save();
        }
}

////////////////////////////////////////////////////////////////////////////////
// ��ʾtr������         is_true ��ʾ�Ƿ���ʾ��ʵ���ԣ�������ʾα����
void tr_show_gift(object ob, int is_true)
{
        int i=0, id, num, equiped;
        object me=this_player();
        mapping ap, gift;
        string msg, str, str2, tg;

        if (is_true) tg="gift_apply";
        else tg="pretend_gift";

        if (!ob->query(tg))
                if (!ob->query("tr_info")) return;
                else
                {
                        tell_object(me, "��"+ob->query("unit")+
                        ob->name()+"û�и������ԡ�\n");
                        return;
                }

        ap=tr_queryi(ob);
        tell_object(me, "\n�������ԣ�\n");
        while ( ob->query(tg+"/"+sprintf("%d", i)) )
        {
                sscanf(ob->query(tg+"/"+sprintf("%d", i)),
                        "%d=%d", id, num);
                if (id!=-1) 
                {
                        gift=TR_QUERY->query_gift(id);
                        // ���Լ���������Ժ���
                        if (strsrch(gift["type"], "uni=")!=-1)  
                        {
                
                        }
                        else
                        {
                                equiped=tr_querya(ob)["need_equip"];
                                sscanf(gift["gift_name"], "%s=%s", str, str2);
                                switch (gift["type"])
                                {
                                case "+temp":
                                        if (equiped==1) msg=CYN"װ����";
                                        else if (equiped==-1) msg=CYN"ʹ�ú�";
                                        else if (equiped==-2) msg=CYN"��Ƕ��֮��";
                                        else msg=CYN"Я����";
                                        msg+="��ʱ���� "+sprintf("%d", num)
                                                + " "+str2+str+NOR;
                                        break;
                                case "-temp":
                                        if (equiped==1) msg=CYN"װ����";
                                        else if (equiped==-1) msg=CYN"ʹ�ú�";
                                        else if (equiped==-2) msg=CYN"��Ƕ��֮��";
                                        else msg=CYN"Я����";
                                        msg+="��ʱ���� "+sprintf("%d", num)
                                                + " "+str2+str+NOR;
                                        break;
                                case "+max":
                                        if (equiped==1) msg=CYN"װ����";
                                        else if (equiped==-1) msg=CYN"ʹ�ú�";
                                        else if (equiped==-2) msg=CYN"��Ƕ��֮��";
                                        else msg=CYN"Я����";
                                        msg+="�������� "+sprintf("%d", num)
                                                + " "+str2+str+"���Զ���ʧ"NOR;
                                        break;
                                case "-max":
                                        if (equiped==1) msg=CYN"װ����";
                                        else if (equiped==-1) msg=CYN"ʹ�ú�";
                                        else if (equiped==-2) msg=CYN"��Ƕ��֮��";
                                        else msg=CYN"Я����";
                                        msg+="���ü��� "+sprintf("%d", num)
                                                + " "+str2+str+"���Զ���ʧ"NOR;
                                        break;
                                default:
                                        msg=CYN"--- * װ �� * ---"NOR;
                                        break;
                                }
                                tell_object(this_player(), "   "+msg+"\n");
                        }
                }
                i++;
        }
}

////////////////////////////////////////////////////////////////////////////////
// ��ʾtr��װ������             is_true ��ʾ�Ƿ���ʾ��ʵ���ƣ�������ʾα����
// Ŀǰֻ���� is_true=1
void tr_show_limit(object ob, int is_true)
{
        int i=0, id, num;
        object me=this_player();
        mapping lim;
        string msg, str, tg;

        //if (is_true) tg="gift_limit";
        //else tg="pretend_limit";

        tg="gift_limit";

        if (!ob->query(tg)) return;

        tell_object(me, "\n����������\n");
        
        while ( ob->query(tg+"/"+sprintf("%d", i)) )
        {
                str=ob->query(tg+"/"+sprintf("%d", i));
                sscanf(str, "%d=%d", id, num);
                lim=TR_QUERY->query_limit(id);
                if (tr_on_limit(me, str)) msg=CYN"   ";
                else msg=RED"   ";
                msg+=sprintf("%d",num)+" ";
                if (lim["type"]<=-1) msg+="��";
                else msg+="��";
                msg+=lim["name"];
                tell_object(me, msg+"\n"NOR);
                i++;
        }
}

////////////////////////////////////////////////////////////////////////////////
// ʵ��tr������         flag=1��ʾʵ�֣�=0��ʾȡ��
void tr_apply_gift(object ob, int flag)
{
        int i=0, j, id, num, seed=1, max=0;
        object me=this_player();
        mapping gift;
        string aname, tg;

        // ����ִ�мٵ����ԣ�����֮���ִ���������
        if (ob->query("pretend_gift"))
                tg="pretend_gift";
        else if (ob->query("gift_apply"))
                tg="gift_apply";
        else return;

        if (!flag) seed=-1;     // ȡ������
        //ap=tr_queryi(ob);
        while ( ob->query(tg+"/"+sprintf("%d", i)) )
        {
                sscanf(ob->query(tg+"/"+sprintf("%d", i)),
                        "%d=%d", id, num);
                num=num*seed;
                if (id!=-1) 
                {
                        gift=TR_QUERY->query_gift(id);
                        sscanf(gift["gift"], "%s=%*d", aname);
                        // ���Լ���������Ժ���
                        if (strsrch(gift["type"], "uni=")!=-1)  
                        {
                
                        }
                        else
                        {
                                //equiped=tr_querya(ob)["need_equip"];
                                switch (gift["type"])
                                {
                                case "+temp":
                                        log_file("USAGE", "tr"+ob->short()+"�������� "+aname+" "+
                                                sprintf("%d �� �� %s (%s)\n",
                                                num, me->short(), 
                                                ctime(time())) );
                                        //if (equiped==1)
                                                me->add_temp("apply/"+aname, num);
                                        break;
                                case "-temp":
                                        log_file("USAGE", "tr"+ob->short()+"�������� "+aname+" "+
                                                sprintf("%d �� �� %s (%s)\n",
                                                num, me->short(), 
                                                ctime(time())) );
                                        //if (equiped==1)
                                                me->add_temp("apply/"+aname, num);
                                        break;
                                case "+max":
                                        log_file("USAGE", "tr"+ob->short()+"�������� "+aname+" "+
                                                sprintf("%d �� �� %s (%s)\n",
                                                num, me->short(), 
                                                ctime(time())) );
                                        if (!gift["add_type"])  // �ӵ�����data��
                                                me->add(aname, num);
                                        else    // �ӵ�skills��
                                        {
                                                me->set_skill(aname,
                                                        (int)me->query_skill(aname, 1)
                                                        +num);
                                                if ((int)me->query_skill(aname, 1)<1)
                                                        me->abandon_skill(aname);
                                        }
                                        //ɾ�������ԣ�������������mapping
                                        j=i+1;
                                        while (ob->query(tg+"/"+sprintf("%d", j)))
                                        {
                                                ob->set(tg+"/"+sprintf("%d", j-1)),
                                                        ob->query(tg+"/"+sprintf("%d", j));
                                                j++;
                                        }
                                        ob->delete(tg+"/"+sprintf("%d", j-1));
                                        i--;
                                        max=1;
                                        break;
                                case "-max":
                                        log_file("USAGE", "tr"+ob->short()+"�������� "+aname+" "+
                                                sprintf("%d �� �� %s (%s)\n",
                                                num, me->short(), 
                                                ctime(time())) );
                                        if (gift["add_type"])   // �ӵ�����data��
                                                me->add(aname, -num);
                                        else    // �ӵ�skills��
                                        {
                                                me->set_skill(aname,
                                                        (int)me->query_skill(aname, 1)
                                                        -num);
                                                if ((int)me->query_skill(aname, 1)<1)
                                                        me->abandon_skill(aname);
                                        }
                                        //ɾ�������ԣ�������������mapping
                                        j=i+1;
                                        while (ob->query(tg+"/"+sprintf("%d", j)))
                                        {
                                                ob->set(tg+"/"+sprintf("%d", j-1)),
                                                        ob->query(tg+"/"+sprintf("%d", j));
                                                j++;
                                        }
                                        ob->delete(tg+"/"+sprintf("%d", j-1));
                                        i--;
                                        max=1;
                                        break;
                                default:
                                        //msg=CYN"--- * װ �� * ---"NOR;
                                        break;
                                }
                        }
                }
                i++;
        }

        // ���������Եģ���Ҫsave()һ��
        if (max)
        {
                if (ob->query("equipped"))
                {
                        ob->delete("equipped");
                        ob->save();
                        ob->set("equipped");
                }
                else ob->save();
        }

        if (!flag) ob->delete("tr_info/apply");
        else ob->set("tr_info/apply", 1);
                
}

////////////////////////////////////////////////////////////////////////////////
// Ϊtr����action
int tr_do_look(string str);
int tr_do_recognize(string str);
int tr_do_recgsure(string str);
int tr_do_recglike(string str);

void tr_add_action()
{
        add_action("do_look","look");
    //add_action("do_wield","wield"); 
        //add_action("do_unwield","unwield");
    //add_action("do_wear","wear"); 
        //add_action("do_remove","remove");
    add_action("do_drop","drop"); 
        add_action("tr_do_recognize", "recg");
        add_action("tr_do_recognize", "jianding");
        add_action("tr_do_recgsure", "recgsure");
        add_action("tr_do_recgsure", "jdsure");
        add_action("tr_do_recglike", "recglike");
        add_action("tr_do_recglike", "recglove");
        add_action("tr_do_recglike", "recgwant");
        add_action("tr_do_recglike", "jdlike");
        add_action("tr_do_recglike", "jdlove");
        add_action("tr_do_recglike", "jdwant");
    //add_action("do_auc","auc"); 
    //add_action("do_give","give");
     
}

int tr_do_look(string str)
{  
        int i;
        object me=this_player();
        object ob;//=this_object();
        string msg;

        if (!str) return 0;
        if (str) str = lower_case(str);
        // δ����ʶ�������ڵ��ϣ��޷��������ԣ����ܿ�������
        if ( !(ob = present(str, me)) )  return 0;

        if ( !ob->query("tr_info") ) return 0;

        tell_object(me, ob->query("long"));

        // ��ʾװ��Ҫ��, δ��������Ʒû��װ������
        if (ob->query("gift_limit") &&
                ob->query("tr_ident") &&
                !ob->query("pretend_gift"))
        {
                tr_show_limit(ob, (int)ob->query("tr_ident",1));
        }

        // ��ʾװ������
        if (ob->query("pretend_gift")) tr_show_gift(ob, 0);
        else tr_show_gift(ob, 1);
        //else tr_show_gift(ob, (int)ob->query("tr_ident",1));

        // ��ʾ��ʯ
        if (ob->query("tr_info/gems"))
        {
                msg=CYN"   ("+chinese_number(ob->query("tr_info/gems",1))+"����ʯ�׶���";
                if (!ob->query("tr_info/gemed"))
                {
                        msg+="�ޱ�ʯ��Ƕ)\n";
                }
                else
                {
                        msg+="�Ѿ���Ƕ"+chinese_number((int)ob->query("gift_gemd",1))+"����ʯ)\n";
                        for (i=0; i<(int)ob->query("tr_info/gemed",1); i++)
                        {
                                //msg+=CYN"    "+ob->query("gift_gem/chn_gem"+sprintf("%d",i+1))+CYN" ("+
                                        //ob->query("gift_gem/gem"+sprintf("%d",i+1))+")\n";
                        }
                }
                tell_object(me,msg+NOR);
        }
        
        // ��ʾ�Ƿ�auto_load
        if (ob->query("tr_info/autoload"))
                tell_object(me, HIG"   <׷�������ߣ������Զ�����>\n"NOR);
        else
                tell_object(me, CYN"   <�������뿪ʱ�������ڵ���>\n"NOR);

        return 1;    
}    

int tr_do_recognize(string str)
{  
        int i;
        int exp, pot, skill, tr_lv;
        int chance;
        object ob;
        object me=this_player();
        string msg;

        if (!str) 
        {
                write(@HELP


ָ���ʽ : 
   recg xxx
   jianding xxx

��ָ����԰�����ʶ��δ��������Ʒ��

HELP
                );
                return 1;
        }

        if (str) str = lower_case(str);

        if ( !ob = present(str, me) ) 
                return notify_fail("��ֻ�ܼ����Լ�Я������Ʒ��\n");

//        if (!me->query_skill("recognize"))
        if (!me->query_skill("literate"))
                return notify_fail("�㻹û�м�����������\n");

        if ( !ob->query("tr_info") )
                return notify_fail("����Ʒ�޷�������\n");

        if (ob->query("tr_ident")) 
                return notify_fail("����Ʒ�Ѿ���������\n");

        tr_lv=(int)ob->query("tr_info/l", 1);
//        skill=(int)me->query_skill("recognize", 1);
        skill=(int)me->query_skill("literate", 1);

        exp=5+random(6);        // ����exp
        pot=1+random(2);        // ����pot

        if (me->query("combat_exp", 1)<exp+10)
                return notify_fail("���ʵս���鲻�����޷���������Ʒ��\n");

        if (me->query("potential", 1)<pot+1)
                return notify_fail("���Ǳ�ܲ��㣬�޷���������Ʒ��\n");

        i=ob->query("tr_info/apply");
        if (i)  // ж����������
    {
                tr_apply_gift(ob, 0);
                if (ob->query("tr_sprite"))
                        ob->set_heart_beat(0);
    }

        if (skill<100)  // 100����ǰ�ĳɹ���
        {
                chance=10+skill/10;
                chance+=(int)me->query("kar", 1)/10
                        + (int)me->query("int", 1)/10;
                if (chance>25) chance=25;
        }
        else
        {
                if (skill>300) skill=300;
                chance=20+skill/5;
                chance+=(int)me->query("kar", 1)/10
                        + (int)me->query("int", 1)/10;
                if (chance>61) chance=61;
        }

        if (random(101) < chance)
        {
                tr_revert(ob);
                ob->set("tr_ident", 0);
                ob->set("tr_success", 1);
        }
        else
        {
                ob->set("tr_success", -1);
                tr_pretend(ob);
        }

        tell_object(me, "������ɣ�\n\n");
        me->add("combat_exp", -exp);
        me->add("potential", -pot);
//    me->improve_skill( "recognize", random(5), 1);
    me->improve_skill( "literate", random(5), 1);

        tr_do_look(ob->query("id"));

        if (tr_lv>3 && random(100)<tr_lv*10)
        {
                switch (tr_lv)
                {
                case 4: msg="\n�����Ʒ�����ԽϺ�"; break;
        case 5: msg="\n�����Ʒ�����Ժܺ�"; break;
        default : msg=HIG"\n�����Ʒ�м�Ʒ����"; break;
                }
                msg+="��ֵ���ղء�\n"NOR;
                write(msg);
        }

        // ��ֹflood����
        me->start_busy(2);

        // �������������Ӳ�̸��������Ƕ�player�����Ի�һЩ
        if (ob->query("tr_info/autoload")) ob->save();

        return 1;
} 

int tr_do_recgsure(string str)
{  
        int i;
        int exp, pot, imp, skill, tr_lv;
        object ob;
        object me=this_player();
        string msg;

        if (!str) 
        {
                write(@HELP


ָ���ʽ : 
   recgsure xxx
   jdsure xxx

��ָ�����ȷ����ʶ��δ��������Ʒ��
������Ϊ��������Ʒ�Ǹ���Ʒ�ı�����ò������ʹ�����ָ�

HELP
                );
                return 1;
        }

        if (str) str = lower_case(str);

        if ( !ob = present(str, me) ) 
                return notify_fail("��ֻ��ȷ���Լ�Я������Ʒ��\n");

//        if (!me->query_skill("recognize"))
        if (!me->query_skill("literate"))
                return notify_fail("�㻹û�м�����������\n");

        if ( !ob->query("tr_info") )
                return notify_fail("����Ʒ�޷�������\n");

        if (ob->query("tr_ident")) 
                return notify_fail("����Ʒ�Ѿ���������\n");

        if (!ob->query("tr_success")) 
                return notify_fail("�㻹û�м���������Ʒ��\n");

        tr_lv=(int)ob->query("tr_info/l", 1);
//        skill=(int)me->query_skill("recognize", 1);
        skill=(int)me->query_skill("literate", 1);

        i=ob->query("tr_info/apply");
        if (i)  // ж����������
    {
                tr_apply_gift(ob, 0);
                if (ob->query("tr_sprite"))
                        ob->set_heart_beat(0);
    }

        if ((int)ob->query("tr_success", 1)==1)
        {
                ob->set("tr_ident", 1);
                ob->delete("tr_success");
                ob->delete("hide_name");
                ob->delete("hide_id");
                ob->delete("hide_value");
                ob->delete("hide_damage");
                write("
�������������������ȷ�ġ�
������������������
������������������������������\n"+
HIC "��ϲ�㣬��ļ����������ȷ�ģ�\n\n" NOR);
                if (skill<100)
                {
                        exp=to_int(500 * (170-skill-tr_lv*10)/170+random(tr_lv)*10);
                        pot=to_int(50 * (170-skill-tr_lv*10)/170+random(tr_lv));
                }
                else
                {
                        if (skill>300) skill=300;
                        exp=to_int(1000 * (370-skill-tr_lv*10)/370
                                +random(tr_lv)*10+random(skill));
                        pot=to_int(200 * (370-skill-tr_lv*10)/370
                                +random(tr_lv)+random(skill/10));
                }
                msg="ͨ�������Ʒ�����������ˣ�\n" WHT;
                msg+="    "+sprintf("%d ��ʵս����\n", exp);
                msg+="    "+sprintf("%d ��Ǳ��\n" NOR, pot);
                write(msg);
                i=me->query_skill("literate",1);
                imp=to_int( skill*10 + (i+random(i))/2 );
                me->add("combat_exp", exp);
                me->add("potential", pot);
                me->improve_skill( "recognize", imp );
        }
        else    // ʧ�ܲ�����exp,pot,skill
        {
                write("
�������������������ȷ�ġ�
��������������
������������������������
���񡭡����������Ԥ�ڵ�������\n
����ʧ��һЩʵս�����Ǳ�ܡ�\n\n");
                exp=10+random(tr_lv);
                pot=1+random(tr_lv/2);
                me->add("combat_exp", -to_int(exp));
                me->add("potential", -to_int(pot));
                if (me->query("combat_exp", 1)<1)
                        me->set("combat_exp", 0);
                if (me->query("potential", 1)<1)
                        me->set("potential", 0);
                // ʧ�ܵĻ���������skill��������bug...
                //me->improve_skill( "recognize", to_int(imp/2) );
        }

        return 1;
} 

int tr_do_recglike(string str)
{  
        int i;
        int exp, pot, skill, tr_lv;
        object ob;
        object me=this_player();
        string msg;

        if (!str) 
        {
                write(@HELP


ָ���ʽ : 
   recglike xxx
   recglove xxx
   recgwant xxx
   jdlike xxx
   jdlove xxx
   jdwant xxx

��ָ���ʾ�����δ��������Ʒ��
����ϲ��δ������Ʒ�����Ի����֣�����ʹ�����ָ��
���ϸ���Ʒ�ѱ����������Ҹ���Ʒ�����ӵ���ߣ�����
��Ϊӵ�����뿪����ʧ��

ע�⣺ʹ�ô�ָ�����һ����Ǳ�ܺ�ʵս���飡

HELP
                );
                return 1;
        }

        if (str) str = lower_case(str);

        if ( !ob = present(str, me) ) 
                return notify_fail("��ֻ��ȷ���Լ�Я������Ʒ��\n");

//        if (!me->query_skill("recognize"))
        if (!me->query_skill("literate"))
                return notify_fail("�㻹û�м�����������\n");

        if ( !ob->query("tr_info") )
                return notify_fail("����Ʒ�޷�������\n");

        if (ob->query("tr_ident")) 
                return notify_fail("����Ʒ�Ѿ���������\n");

        tr_lv=(int)ob->query("tr_info/l", 1);
//        skill=(int)me->query_skill("recognize", 1);
        skill=(int)me->query_skill("literate", 1);

        exp=to_int(1000 * (70-tr_lv*10)/70+random(tr_lv)*10);
        pot=to_int(100 * (70-tr_lv*10)/70+random(tr_lv));

        if (me->query("combat_exp", 1)<exp+10)
                return notify_fail("���ʵս���鲻����ǿ�Ƴ��϶������к���\n");

        if (me->query("potential", 1)<pot+1)
                return notify_fail("���Ǳ�ܲ��㣬ǿ�Ƴ��ϻ����˴��ԣ�\n");

        i=ob->query("tr_info/apply");
        if (i)  // ж����������
    {
                tr_apply_gift(ob, 0);
                if (ob->query("tr_sprite"))
                        ob->set_heart_beat(0);
    }

        // ת��αgiftΪ��gift
        if ((int)ob->query("tr_success", 1)==-1)
        {
                ob->delete("gift_apply");
                if (ob->query("pretend_gift"))
                {
                        i=0;
                        while (ob->query("pretend_gift/"+sprintf("%d", i)))
                        {
                                ob->set("gift_apply/"+sprintf("%d", i),
                                        ob->query("pretend_gift/"+sprintf("%d", i)));
                                i++;
                        }
                }
        }

        ob->set("tr_ident", 1);
        ob->delete("pretend_gift");
        ob->delete("tr_success");
        ob->delete("hide_name");
        ob->delete("hide_id");
        ob->delete("hide_value");
        ob->delete("hide_damage");

        write("
��ϲ�������Ʒ���ڵ����ֺ����ԣ�
���ǳ����������Ѽ�����Ʒ��\n\n");

        msg="���������Ʒ���������ˣ�\n" WHT;
        msg+="    "+sprintf("%d ��ʵս����\n", exp);
        msg+="    "+sprintf("%d ��Ǳ��\n\n" NOR, pot);
        write(msg);
        me->add("combat_exp", -exp);
        me->add("potential", -pot);

        if (!ob->query("tr_info/file"))
        {
                ob->set("tr_info/autoload", 1);
                msg=(tr_queryt(ob)["random_id"] ?
                        tr_queryt(ob)["id/0"]:
                        tr_queryt(ob)["id"]);
                ob->set("tr_info/file", 
                        sprintf(TR_SAVE_DIR "%c/%s%d", msg[0], msg, time()));
        }

        ob->save();

        tr_do_look(ob->query("id"));

        return 1;
} 

int tr_chance(object ob)
{
        int seed=1;
        object winner;
        
        if (living(ob))
        {
                if (ob->query_temp("last_damage_from"))
                {
                        winner = ob->query_temp("last_damage_from");
                        seed+=winner->query("kar", 1)*5;
                        seed+=(winner->query_int()+winner->query_cor())/2;
                        if (F_DTIME->query_day_in_month()%7==0)
                                seed+=7*random(F_DTIME->query_day_in_month())+10;
                        seed+=(winner->query("age", 1)-13)*10;
                        seed+=winner->query_temp("apply/magic_find", 1);
                }
                else    // ��Ȼ����
                {
                        seed+=random(300);
                        // ������7��������
                        if (F_DTIME->query_day_in_month()%7==0)
                                seed+=7*random(F_DTIME->query_day_in_month())+10;
                }
        }
        else
        {
                seed+=random(300);
                // ������7��������
                        if (F_DTIME->query_day_in_month()%7==0)
                                seed+=7*random(F_DTIME->query_day_in_month())+10;
        }

        if (wizardp(this_player()))
                printf(WHT "debug: �������ʣ�%d\n" NOR, seed);
        if (seed>800) seed=800;
        if (random(1000) < seed) 
                return seed;  // find treasure!

        return 0;       
}

// ���ɱ���ob
int tr_make(object ob)
{
        int i, j, num, seed, temp, region;
        int *attr, *type, *level;
        object tr;
        object winner;

        if (wizardp(this_player()))
                printf(WHT "debug: object=%s\n" NOR, ob->short());

        if (!ob || !objectp(ob)) return 0;

        if (!(seed=tr_chance(ob))) return 0;
        //if (living(ob)) seed=random(1000);
                

        // ȡ������
        if (living(ob))
        {
                if (ob->query_temp("last_damage_from"))
                {
                        winner = ob->query_temp("last_damage_from");
                        num=random(seed/100)+1;
                        if (num>TR_MAX_DROPS) 
                                num=TR_MAX_DROPS;
                }
                else
                {
                        num=random(TR_MAX_DROPS/3)+1;
                }
        }
        else
        {
                num=random(TR_MAX_DROPS/3)+1;
        }

        if (num<1) num=1;

        num=to_int(num);

        if (wizardp(this_player()))
                printf(WHT "debug: ����������%d\n" NOR, num);

        attr=allocate(num);
        type=allocate(num);
        level=allocate(num);

        // ʹ��������䷨�������ı���
        // ȡ������
        for (i=0; i<num; i++)
        {
                // ȡ�û�������
                temp=random(to_int(seed*3/2));
                if (temp>1000) temp=1000;
                if (temp<1) temp=1;
                // ����attr
                attr[i]=0;      // ����Ҫ=0
                region=0;
                for (j=0; j<TR_ATTRIBUTE->query_total(); j++)
                {
                        if ( temp>=region &&
                                 temp<region+TR_ATTRIBUTE->query(j)["chance"] )
                        {
                                if ( TR_ATTRIBUTE->query(j)["enable"] )
                                        attr[i]=j;
                                break;
                        }
                        region+=TR_ATTRIBUTE->query(j)["chance"];
                }
        }

        // ȡ������
        for (i=0; i<num; i++)
        {
                // ȡ�û�������
                temp=random(to_int(seed*3/2));
                if (temp>1000) temp=1000;
                if (temp<1) temp=1;
                // ����type
                type[i]=0;      // ����Ҫ=0
                region=0;
                for (j=0; j<TR_TYPE->query_total(attr[i]); j++)
                {
                        if ( temp>=region &&
                                 temp<region+TR_TYPE->query(attr[i], j)["chance"] )
                        {
                                // ������Ʒ�Ƿ񿪷�
                                if ( TR_TYPE->query(attr[i], j)["enable"] )
                                        type[i]=j;
                                break;
                        }
                        region+=TR_TYPE->query(j)["chance"];
                }
        }

        // ȡ�õȼ�
        for (i=0; i<num; i++)
        {
                // ȡ�û�������
                temp=random(to_int(seed*3/2));
                if (temp>1000) temp=1000;
                if (temp<1) temp=1;
                level[i]=to_int((TR_MAX_LEVEL-1)*temp/800);
                if (level[i]>=TR_MAX_LEVEL)
                        level[i]=TR_MAX_LEVEL-1;
                if (level[0]<0)
                        level[0]=0;
        }
        
        for (i=0; i<num; i++)
        {
                // ���ɻ�������
                switch (attr[i])
                {
                //case 1:
                //      break;

                default:  // 0
                        switch (type[i])
                        {
                        case 1:
                                tr=new(__DIR__"tr_blade");
                                break;
                        default:  // 0
                                tr=new(__DIR__"tr_sword");
                                break;
                        }
                        break;
                }
                // ʵ����Ϊ�������
                if (wizardp(this_player()))
                {
                        printf(WHT "debug: tr��%d, %d, %d\n" NOR, 
                                attr[i], type[i], level[i]);
                }

                tr_copy_basic_info(tr, 
                        attr[i],type[i],level[i], -1);

                // �ƶ�tr
                if (living(ob) || ob->query_temp("unconcious"))
                {
                        if (random(100)<50)     // ��������
                                tr->move(ob);
                        else  // ���ڵ���
                        {
                                if (objectp(environment(tr)))
                                {
                                        message_vision("�㿴����$N���ϵ�����һ"
                                                +tr->query("unit")+tr->short()+"��\n", ob);
                                        tr->move(environment(tr));
                                }
                                else tr->move(ob);
                        }
                }
                else
                {
                        message_vision("���ƺ�����������Щʲô��\n", this_player());
                        tr->move(ob);
                }
        }

        printf(WHT"DEBUG: this_ob=%s\n"NOR, ob->short());
        return 1;
}

