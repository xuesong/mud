// goldbow.c

#include <ansi.h>

inherit __DIR__"bow";

void create()
{
        set_name(HIR "��"HIY"��"HIG"��" NOR, ({ "sheri gong", "sheri", "gong", "bow" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", HIR "����һ���񹭣����������˵�����ϵ�̫���������䡣\n" NOR);
                //set("no_sell", "�ҵ��졭�������Ķ�����Ҳ����������");
		set("value", 200000);
                set("power", 250000);   // ��������
                set("accuracy", 200);   // ׼ȷ��200%
        }
        setup();
}