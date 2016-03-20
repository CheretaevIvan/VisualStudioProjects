namespace CiscoInit
{
    partial class CiscoForm
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(CiscoForm));
            System.Windows.Forms.Label idLabel;
            System.Windows.Forms.Label numberLabel;
            System.Windows.Forms.Label typeLabel;
            System.Windows.Forms.Label nativeVlan_IdLabel;
            System.Windows.Forms.Label switch_IdLabel;
            this.button1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.ciscoDataSet = new CiscoInit.Database.CiscoDataSet();
            this.interfacesBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.interfacesTableAdapter = new CiscoInit.Database.CiscoDataSetTableAdapters.InterfacesTableAdapter();
            this.tableAdapterManager = new CiscoInit.Database.CiscoDataSetTableAdapters.TableAdapterManager();
            this.interfacesBindingNavigator = new System.Windows.Forms.BindingNavigator(this.components);
            this.bindingNavigatorMoveFirstItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorMovePreviousItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorSeparator = new System.Windows.Forms.ToolStripSeparator();
            this.bindingNavigatorPositionItem = new System.Windows.Forms.ToolStripTextBox();
            this.bindingNavigatorCountItem = new System.Windows.Forms.ToolStripLabel();
            this.bindingNavigatorSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.bindingNavigatorMoveNextItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorMoveLastItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.bindingNavigatorAddNewItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorDeleteItem = new System.Windows.Forms.ToolStripButton();
            this.interfacesBindingNavigatorSaveItem = new System.Windows.Forms.ToolStripButton();
            this.idTextBox = new System.Windows.Forms.TextBox();
            this.numberTextBox = new System.Windows.Forms.TextBox();
            this.typeTextBox = new System.Windows.Forms.TextBox();
            this.nativeVlan_IdTextBox = new System.Windows.Forms.TextBox();
            this.switch_IdTextBox = new System.Windows.Forms.TextBox();
            this.switchRoutersBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.switchRoutersTableAdapter = new CiscoInit.Database.CiscoDataSetTableAdapters.SwitchRoutersTableAdapter();
            this.switchRoutersListBox = new System.Windows.Forms.ListBox();
            idLabel = new System.Windows.Forms.Label();
            numberLabel = new System.Windows.Forms.Label();
            typeLabel = new System.Windows.Forms.Label();
            nativeVlan_IdLabel = new System.Windows.Forms.Label();
            switch_IdLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.ciscoDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.interfacesBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.interfacesBindingNavigator)).BeginInit();
            this.interfacesBindingNavigator.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.switchRoutersBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(574, 505);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(94, 38);
            this.button1.TabIndex = 0;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(653, 480);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "label1";
            // 
            // ciscoDataSet
            // 
            this.ciscoDataSet.DataSetName = "CiscoDataSet";
            this.ciscoDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // interfacesBindingSource
            // 
            this.interfacesBindingSource.DataMember = "Interfaces";
            this.interfacesBindingSource.DataSource = this.ciscoDataSet;
            // 
            // interfacesTableAdapter
            // 
            this.interfacesTableAdapter.ClearBeforeFill = true;
            // 
            // tableAdapterManager
            // 
            this.tableAdapterManager.BackupDataSetBeforeUpdate = false;
            this.tableAdapterManager.InterfacesTableAdapter = this.interfacesTableAdapter;
            this.tableAdapterManager.SwitchRoutersTableAdapter = this.switchRoutersTableAdapter;
            this.tableAdapterManager.UpdateOrder = CiscoInit.Database.CiscoDataSetTableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete;
            this.tableAdapterManager.VlansTableAdapter = null;
            // 
            // interfacesBindingNavigator
            // 
            this.interfacesBindingNavigator.AddNewItem = this.bindingNavigatorAddNewItem;
            this.interfacesBindingNavigator.BindingSource = this.interfacesBindingSource;
            this.interfacesBindingNavigator.CountItem = this.bindingNavigatorCountItem;
            this.interfacesBindingNavigator.DeleteItem = this.bindingNavigatorDeleteItem;
            this.interfacesBindingNavigator.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.bindingNavigatorMoveFirstItem,
            this.bindingNavigatorMovePreviousItem,
            this.bindingNavigatorSeparator,
            this.bindingNavigatorPositionItem,
            this.bindingNavigatorCountItem,
            this.bindingNavigatorSeparator1,
            this.bindingNavigatorMoveNextItem,
            this.bindingNavigatorMoveLastItem,
            this.bindingNavigatorSeparator2,
            this.bindingNavigatorAddNewItem,
            this.bindingNavigatorDeleteItem,
            this.interfacesBindingNavigatorSaveItem});
            this.interfacesBindingNavigator.Location = new System.Drawing.Point(0, 0);
            this.interfacesBindingNavigator.MoveFirstItem = this.bindingNavigatorMoveFirstItem;
            this.interfacesBindingNavigator.MoveLastItem = this.bindingNavigatorMoveLastItem;
            this.interfacesBindingNavigator.MoveNextItem = this.bindingNavigatorMoveNextItem;
            this.interfacesBindingNavigator.MovePreviousItem = this.bindingNavigatorMovePreviousItem;
            this.interfacesBindingNavigator.Name = "interfacesBindingNavigator";
            this.interfacesBindingNavigator.PositionItem = this.bindingNavigatorPositionItem;
            this.interfacesBindingNavigator.Size = new System.Drawing.Size(709, 25);
            this.interfacesBindingNavigator.TabIndex = 2;
            this.interfacesBindingNavigator.Text = "bindingNavigator1";
            // 
            // bindingNavigatorMoveFirstItem
            // 
            this.bindingNavigatorMoveFirstItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMoveFirstItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveFirstItem.Image")));
            this.bindingNavigatorMoveFirstItem.Name = "bindingNavigatorMoveFirstItem";
            this.bindingNavigatorMoveFirstItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMoveFirstItem.Size = new System.Drawing.Size(23, 22);
            this.bindingNavigatorMoveFirstItem.Text = "Переместить в начало";
            // 
            // bindingNavigatorMovePreviousItem
            // 
            this.bindingNavigatorMovePreviousItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMovePreviousItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMovePreviousItem.Image")));
            this.bindingNavigatorMovePreviousItem.Name = "bindingNavigatorMovePreviousItem";
            this.bindingNavigatorMovePreviousItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMovePreviousItem.Size = new System.Drawing.Size(23, 22);
            this.bindingNavigatorMovePreviousItem.Text = "Переместить назад";
            // 
            // bindingNavigatorSeparator
            // 
            this.bindingNavigatorSeparator.Name = "bindingNavigatorSeparator";
            this.bindingNavigatorSeparator.Size = new System.Drawing.Size(6, 25);
            // 
            // bindingNavigatorPositionItem
            // 
            this.bindingNavigatorPositionItem.AccessibleName = "Положение";
            this.bindingNavigatorPositionItem.AutoSize = false;
            this.bindingNavigatorPositionItem.Name = "bindingNavigatorPositionItem";
            this.bindingNavigatorPositionItem.Size = new System.Drawing.Size(50, 23);
            this.bindingNavigatorPositionItem.Text = "0";
            this.bindingNavigatorPositionItem.ToolTipText = "Текущее положение";
            // 
            // bindingNavigatorCountItem
            // 
            this.bindingNavigatorCountItem.Name = "bindingNavigatorCountItem";
            this.bindingNavigatorCountItem.Size = new System.Drawing.Size(43, 15);
            this.bindingNavigatorCountItem.Text = "для {0}";
            this.bindingNavigatorCountItem.ToolTipText = "Общее число элементов";
            // 
            // bindingNavigatorSeparator1
            // 
            this.bindingNavigatorSeparator1.Name = "bindingNavigatorSeparator";
            this.bindingNavigatorSeparator1.Size = new System.Drawing.Size(6, 6);
            // 
            // bindingNavigatorMoveNextItem
            // 
            this.bindingNavigatorMoveNextItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMoveNextItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveNextItem.Image")));
            this.bindingNavigatorMoveNextItem.Name = "bindingNavigatorMoveNextItem";
            this.bindingNavigatorMoveNextItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMoveNextItem.Size = new System.Drawing.Size(23, 20);
            this.bindingNavigatorMoveNextItem.Text = "Переместить вперед";
            // 
            // bindingNavigatorMoveLastItem
            // 
            this.bindingNavigatorMoveLastItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMoveLastItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveLastItem.Image")));
            this.bindingNavigatorMoveLastItem.Name = "bindingNavigatorMoveLastItem";
            this.bindingNavigatorMoveLastItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMoveLastItem.Size = new System.Drawing.Size(23, 20);
            this.bindingNavigatorMoveLastItem.Text = "Переместить в конец";
            // 
            // bindingNavigatorSeparator2
            // 
            this.bindingNavigatorSeparator2.Name = "bindingNavigatorSeparator";
            this.bindingNavigatorSeparator2.Size = new System.Drawing.Size(6, 6);
            // 
            // bindingNavigatorAddNewItem
            // 
            this.bindingNavigatorAddNewItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorAddNewItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorAddNewItem.Image")));
            this.bindingNavigatorAddNewItem.Name = "bindingNavigatorAddNewItem";
            this.bindingNavigatorAddNewItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorAddNewItem.Size = new System.Drawing.Size(23, 22);
            this.bindingNavigatorAddNewItem.Text = "Добавить";
            // 
            // bindingNavigatorDeleteItem
            // 
            this.bindingNavigatorDeleteItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorDeleteItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorDeleteItem.Image")));
            this.bindingNavigatorDeleteItem.Name = "bindingNavigatorDeleteItem";
            this.bindingNavigatorDeleteItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorDeleteItem.Size = new System.Drawing.Size(23, 20);
            this.bindingNavigatorDeleteItem.Text = "Удалить";
            // 
            // interfacesBindingNavigatorSaveItem
            // 
            this.interfacesBindingNavigatorSaveItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.interfacesBindingNavigatorSaveItem.Image = ((System.Drawing.Image)(resources.GetObject("interfacesBindingNavigatorSaveItem.Image")));
            this.interfacesBindingNavigatorSaveItem.Name = "interfacesBindingNavigatorSaveItem";
            this.interfacesBindingNavigatorSaveItem.Size = new System.Drawing.Size(23, 23);
            this.interfacesBindingNavigatorSaveItem.Text = "Сохранить данные";
            this.interfacesBindingNavigatorSaveItem.Click += new System.EventHandler(this.interfacesBindingNavigatorSaveItem_Click);
            // 
            // idLabel
            // 
            idLabel.AutoSize = true;
            idLabel.Location = new System.Drawing.Point(27, 49);
            idLabel.Name = "idLabel";
            idLabel.Size = new System.Drawing.Size(19, 13);
            idLabel.TabIndex = 3;
            idLabel.Text = "Id:";
            // 
            // idTextBox
            // 
            this.idTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.interfacesBindingSource, "Id", true));
            this.idTextBox.Location = new System.Drawing.Point(110, 46);
            this.idTextBox.Name = "idTextBox";
            this.idTextBox.Size = new System.Drawing.Size(100, 20);
            this.idTextBox.TabIndex = 4;
            // 
            // numberLabel
            // 
            numberLabel.AutoSize = true;
            numberLabel.Location = new System.Drawing.Point(27, 75);
            numberLabel.Name = "numberLabel";
            numberLabel.Size = new System.Drawing.Size(47, 13);
            numberLabel.TabIndex = 5;
            numberLabel.Text = "Number:";
            // 
            // numberTextBox
            // 
            this.numberTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.interfacesBindingSource, "Number", true));
            this.numberTextBox.Location = new System.Drawing.Point(110, 72);
            this.numberTextBox.Name = "numberTextBox";
            this.numberTextBox.Size = new System.Drawing.Size(100, 20);
            this.numberTextBox.TabIndex = 6;
            // 
            // typeLabel
            // 
            typeLabel.AutoSize = true;
            typeLabel.Location = new System.Drawing.Point(27, 101);
            typeLabel.Name = "typeLabel";
            typeLabel.Size = new System.Drawing.Size(34, 13);
            typeLabel.TabIndex = 7;
            typeLabel.Text = "Type:";
            // 
            // typeTextBox
            // 
            this.typeTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.interfacesBindingSource, "Type", true));
            this.typeTextBox.Location = new System.Drawing.Point(110, 98);
            this.typeTextBox.Name = "typeTextBox";
            this.typeTextBox.Size = new System.Drawing.Size(100, 20);
            this.typeTextBox.TabIndex = 8;
            // 
            // nativeVlan_IdLabel
            // 
            nativeVlan_IdLabel.AutoSize = true;
            nativeVlan_IdLabel.Location = new System.Drawing.Point(27, 127);
            nativeVlan_IdLabel.Name = "nativeVlan_IdLabel";
            nativeVlan_IdLabel.Size = new System.Drawing.Size(77, 13);
            nativeVlan_IdLabel.TabIndex = 9;
            nativeVlan_IdLabel.Text = "Native Vlan Id:";
            // 
            // nativeVlan_IdTextBox
            // 
            this.nativeVlan_IdTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.interfacesBindingSource, "NativeVlan_Id", true));
            this.nativeVlan_IdTextBox.Location = new System.Drawing.Point(110, 124);
            this.nativeVlan_IdTextBox.Name = "nativeVlan_IdTextBox";
            this.nativeVlan_IdTextBox.Size = new System.Drawing.Size(100, 20);
            this.nativeVlan_IdTextBox.TabIndex = 10;
            // 
            // switch_IdLabel
            // 
            switch_IdLabel.AutoSize = true;
            switch_IdLabel.Location = new System.Drawing.Point(27, 153);
            switch_IdLabel.Name = "switch_IdLabel";
            switch_IdLabel.Size = new System.Drawing.Size(54, 13);
            switch_IdLabel.TabIndex = 11;
            switch_IdLabel.Text = "Switch Id:";
            // 
            // switch_IdTextBox
            // 
            this.switch_IdTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.interfacesBindingSource, "Switch_Id", true));
            this.switch_IdTextBox.Location = new System.Drawing.Point(110, 150);
            this.switch_IdTextBox.Name = "switch_IdTextBox";
            this.switch_IdTextBox.Size = new System.Drawing.Size(100, 20);
            this.switch_IdTextBox.TabIndex = 12;
            // 
            // switchRoutersBindingSource
            // 
            this.switchRoutersBindingSource.DataMember = "SwitchRouters";
            this.switchRoutersBindingSource.DataSource = this.ciscoDataSet;
            // 
            // switchRoutersTableAdapter
            // 
            this.switchRoutersTableAdapter.ClearBeforeFill = true;
            // 
            // switchRoutersListBox
            // 
            this.switchRoutersListBox.DataSource = this.switchRoutersBindingSource;
            this.switchRoutersListBox.DisplayMember = "Hostname";
            this.switchRoutersListBox.FormattingEnabled = true;
            this.switchRoutersListBox.Location = new System.Drawing.Point(30, 209);
            this.switchRoutersListBox.Name = "switchRoutersListBox";
            this.switchRoutersListBox.Size = new System.Drawing.Size(300, 212);
            this.switchRoutersListBox.TabIndex = 13;
            this.switchRoutersListBox.ValueMember = "Id";
            // 
            // CiscoForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(709, 610);
            this.Controls.Add(this.switchRoutersListBox);
            this.Controls.Add(idLabel);
            this.Controls.Add(this.idTextBox);
            this.Controls.Add(numberLabel);
            this.Controls.Add(this.numberTextBox);
            this.Controls.Add(typeLabel);
            this.Controls.Add(this.typeTextBox);
            this.Controls.Add(nativeVlan_IdLabel);
            this.Controls.Add(this.nativeVlan_IdTextBox);
            this.Controls.Add(switch_IdLabel);
            this.Controls.Add(this.switch_IdTextBox);
            this.Controls.Add(this.interfacesBindingNavigator);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label1);
            this.Name = "CiscoForm";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.CiscoForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.ciscoDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.interfacesBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.interfacesBindingNavigator)).EndInit();
            this.interfacesBindingNavigator.ResumeLayout(false);
            this.interfacesBindingNavigator.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.switchRoutersBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label1;
        private Database.CiscoDataSet ciscoDataSet;
        private System.Windows.Forms.BindingSource interfacesBindingSource;
        private Database.CiscoDataSetTableAdapters.InterfacesTableAdapter interfacesTableAdapter;
        private Database.CiscoDataSetTableAdapters.TableAdapterManager tableAdapterManager;
        private System.Windows.Forms.BindingNavigator interfacesBindingNavigator;
        private System.Windows.Forms.ToolStripButton bindingNavigatorAddNewItem;
        private System.Windows.Forms.ToolStripLabel bindingNavigatorCountItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorDeleteItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveFirstItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMovePreviousItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator;
        private System.Windows.Forms.ToolStripTextBox bindingNavigatorPositionItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator1;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveNextItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveLastItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator2;
        private System.Windows.Forms.ToolStripButton interfacesBindingNavigatorSaveItem;
        private System.Windows.Forms.TextBox idTextBox;
        private System.Windows.Forms.TextBox numberTextBox;
        private System.Windows.Forms.TextBox typeTextBox;
        private System.Windows.Forms.TextBox nativeVlan_IdTextBox;
        private System.Windows.Forms.TextBox switch_IdTextBox;
        private Database.CiscoDataSetTableAdapters.SwitchRoutersTableAdapter switchRoutersTableAdapter;
        private System.Windows.Forms.BindingSource switchRoutersBindingSource;
        private System.Windows.Forms.ListBox switchRoutersListBox;
    }
}

